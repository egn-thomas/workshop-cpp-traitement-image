#include "effet/effet.hpp"

#include <sil/sil.hpp>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>
#include <filesystem>
#include <random>

void nettoyerTerminal()
{
    std::cout << "\033[2J\033[H";
}

std::vector<std::string> setupImages()
{
    std::string chemin{"../images/"};

    std::vector<std::string> nomFichiers{};

    if (std::filesystem::exists(chemin) && std::filesystem::is_directory(chemin))
    {
        for (const auto &entry : std::filesystem::directory_iterator(chemin))
        {
            if (entry.is_regular_file() && (entry.path().extension() == ".png" || entry.path().extension() == ".jpg"))
            {
                nomFichiers.push_back(entry.path().filename().string());
            }
        }
    }
    else
    {
        std::cout << "[ERROR] Le chemin du dossier image n'est pas valide" << std::endl;
    }

    return nomFichiers;
}

using FonctionEffet = sil::Image (*)(sil::Image);

int appliquerEffet(
    std::vector<std::string> const &imagesDisponibles,
    FonctionEffet fonction,
    std::string const &nomEffet,
    std::string const &cheminSortie)
{
    try
    {
        std::cout << "Vous avez sélectionné l'effet \"" << nomEffet << "\".\n"
                  << std::endl;
        sil::Image image{effet::choisirImage(imagesDisponibles)};
        sil::Image imageModifiee{fonction(std::move(image))};
        imageModifiee.save(cheminSortie);
        std::cout << "Image enregistrée dans " << cheminSortie << ".\n"
                  << std::endl;
    }
    catch (std::exception const &erreur)
    {
        std::cerr << "Impossible de traiter l'image : " << erreur.what() << std::endl;
        return 1;
    }
    return 0;
}

int creerImage(
    int largeur,
    int hauteur,
    FonctionEffet fonction,
    std::string const &nomEffet,
    std::string const &cheminSortie)
{
    try
    {
        std::cout << "Vous avez sélectionné la création \"" << nomEffet << "\".\n"
                  << std::endl;

        // On vérifie que l'effet choisi n'est pas l'animation car son fonctionnement est differrent des autres.
        if (nomEffet != "Animation")
        {
            sil::Image image{largeur, hauteur};
            sil::Image imageCreee{fonction(std::move(image))};
            imageCreee.save(cheminSortie);
            std::cout << "Image enregistrée dans " << cheminSortie << ".\n\n\n"
                      << std::endl;
        }
        else
        {
            int i;

            int choix;
            std::cout << "Veuillez entrer la taille du rayon du disque souhaitée (< à 250) : " << std::endl;
            std::cin >> choix;

            for (i = 0; i < 500; i++)
            {
                sil::Image image{largeur, hauteur};
                sil::Image imageCreee{effet::animation(std::move(image), i, choix)};
                imageCreee.save("output/animation/frame" + std::to_string(i) + ".png");
                std::cout << "Images enregistrées dans output/animation/frame...\n\n\n"
                          << std::endl;
            }
        }
    }
    catch (std::exception const &erreur)
    {
        std::cerr << "Impossible de créer l'image : " << erreur.what() << std::endl;
        return 1;
    }
    return 0;
}

int main()
{
    while (true)
    {

        srand(static_cast<unsigned>(time(nullptr)));

        std::cout << "Worshop S1 - Cpp - traitement d'images\n"
                  << std::endl;

        int choix{0};
        std::cout << "Choisissez un effet :" << std::endl;
        std::cout << " 0 - Quitter" << std::endl;
        std::cout << " 1 - Ne garder que le vert" << std::endl;
        std::cout << " 2 - Échanger les canaux" << std::endl;
        std::cout << " 3 - Noir & Blanc" << std::endl;
        std::cout << " 4 - Négatif" << std::endl;
        std::cout << " 5 - Dégradé" << std::endl;
        std::cout << " 6 - Miroir" << std::endl;
        std::cout << " 7 - Image Bruitée" << std::endl;
        std::cout << " 8 - Rotation à 90°" << std::endl;
        std::cout << " 9 - RGB split" << std::endl;
        std::cout << "10 - Luminosité" << std::endl;
        std::cout << "11 - Disque" << std::endl;
        std::cout << "12 - Cercle" << std::endl;
        std::cout << "13 - Animation" << std::endl;
        std::cout << "14 - Rosace" << std::endl;
        std::cout << "15 - Mosaique" << std::endl;
        std::cout << "16 - Mosaique miroir" << std::endl;
        std::cout << "17 - Glitch" << std::endl;
        std::cout << "18 - Tri de pixels" << std::endl;
        std::cout << "19 - Fractales de Mandelbrot" << std::endl;
        std::cout << "20 - Dégradés" << std::endl;
        std::cout << "21 - Tramage" << std::endl;
        std::cout << "22 - Normalisation de l'histogramme" << std::endl;
        std::cout << "23 - Vortex" << std::endl;
        std::cout << "24 - Convolution" << std::endl;
        std::cout << "25 - Diamond square" << std::endl;
        std::cout << "26 - Colorer la height map" << std::endl;

        std::cout << "\n\nVotre choix : ";

        std::cin >> choix;

        nettoyerTerminal();

        std::vector<std::string> imagesDisponibles = setupImages();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choix)
        {
        case 0:
            return 0;
        case 1:
            appliquerEffet(imagesDisponibles, effet::neGarderQueLeVert, "Ne garder que le vert", "output/image_verte.png");
            break;
        case 2:
            appliquerEffet(imagesDisponibles, effet::echangerLesCanaux, "Échanger les canaux", "output/image_echange.png");
            break;
        case 3:
            appliquerEffet(imagesDisponibles, effet::noirEtBlanc, "Noir & Blanc", "output/image_n&b.png");
            break;
        case 4:
            appliquerEffet(imagesDisponibles, effet::inverser, "Négatif", "output/image_negatif.png");
            break;
        case 5:
            creerImage(300, 300, effet::degrade, "Dégradé", "output/image_degrade.png");
            break;
        case 6:
            appliquerEffet(imagesDisponibles, effet::miroir, "Miroir", "output/image_miroir.png");
            break;
        case 7:
            appliquerEffet(imagesDisponibles, effet::bruit, "Image bruitée", "output/image_bruit.png");
            break;
        case 8:
            appliquerEffet(imagesDisponibles, effet::rotation, "Rotation à 90°", "output/image_rotation.png");
            break;
        case 9:
            appliquerEffet(imagesDisponibles, effet::rgbSplit, "RGB split", "output/image_rgbSplit.png");
            break;
        case 10:
            appliquerEffet(imagesDisponibles, effet::luminosite, "Luminosité", "output/image_luminosite.png");
            break;
        case 11:
            creerImage(500, 500, effet::disque, "Disque", "output/image_disque.png");
            break;
        case 12:
            creerImage(500, 500, effet::cercle, "Cercle", "output/image_cercle.png");
            break;
        case 13:
            creerImage(500, 500, effet::disque, "Animation", "");
            break;
        case 14:
            creerImage(500, 500, effet::rosace, "Rosace", "output/image_rosace.png");
            break;
        case 15:
            appliquerEffet(imagesDisponibles, effet::mosaique, "Mosaique", "output/image_mosaique.png");
            break;
        case 16:
            appliquerEffet(imagesDisponibles, effet::mosaiqueMiroir, "Mosaique miroir", "output/image_mosaique_miroir.png");
            break;
        case 17:
            appliquerEffet(imagesDisponibles, effet::glitch, "Glitch", "output/image_glitch.png");
            break;
        case 18:
            appliquerEffet(imagesDisponibles, effet::triPixels, "Tri de pixels", "output/image_tri_pixels.png");
            break;
        case 19:
            creerImage(1000, 1000, effet::mandelbrot, "Fractale de Mandelbrot", "output/image_mandelbrot.png");
            break;
        case 20:
            creerImage(500, 500, effet::degradeLab, "Dégradé dans l'espace de couleur Lab", "output/image_degrade_lab.png");
            break;
        case 21:
            appliquerEffet(imagesDisponibles, effet::tramage, "Tramage", "output/image_tramage.png");
            break;
        case 22:
            appliquerEffet(imagesDisponibles, effet::normalisationHistogramme, "Normalisation de l'histogramme", "output/image_histogramme.png");
            break;
        case 23:
            appliquerEffet(imagesDisponibles, effet::vortex, "Vortex", "output/image_vortex.png");
            break;
        case 24:
            appliquerEffet(imagesDisponibles, effet::convolution, "Convolution", "output/image_convolution.png");
            break;
        case 25:
            creerImage(513, 513, effet::diamondSquare, "Diamond square", "output/image_diamond_square.png");
            break;
        case 26:
            appliquerEffet(imagesDisponibles, effet::colorerHeightMap, "Colorer la height map", "output/image_height_map_coloree.png");
            break;
        default:
            std::cerr << "Choix invalide." << std::endl;
        }
    }
}