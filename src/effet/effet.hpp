#pragma once

#include <sil/sil.hpp>
#include <string>
#include <vector>

namespace effet
{
    sil::Image choisirImage(std::vector<std::string>);
    sil::Image neGarderQueLeVert(sil::Image image);
    sil::Image rotation(sil::Image image);
    sil::Image noirEtBlanc(sil::Image image);
    sil::Image rgbSplit(sil::Image image);
    sil::Image inverser(sil::Image image);
    sil::Image miroir(sil::Image image);
    sil::Image bruit(sil::Image image);
    sil::Image echangerLesCanaux(sil::Image image);
    sil::Image luminosite(sil::Image image);
    sil::Image degrade(sil::Image image);
    sil::Image disque(sil::Image image);
    sil::Image cercle(sil::Image image);
    sil::Image animation(sil::Image image, int frame, int choix);
    sil::Image rosace(sil::Image image);
    sil::Image mosaique(sil::Image image);
    sil::Image mosaiqueMiroir(sil::Image image);
    sil::Image glitch(sil::Image image);
    sil::Image triPixels(sil::Image image);
    sil::Image mandelbrot(sil::Image image);
    sil::Image degradeLab(sil::Image image);
    sil::Image tramage(sil::Image image);
    sil::Image normalisationHistogramme(sil::Image image);
    sil::Image vortex(sil::Image image);
    sil::Image convolution(sil::Image image);
    sil::Image netteteContours(sil::Image image);
    sil::Image filtresSeparables(sil::Image image);
    sil::Image differencesGaussiennes(sil::Image image);
    sil::Image kMeans(sil::Image image);
    sil::Image kuwahara(sil::Image image);
    sil::Image diamondSquare(sil::Image image);
    sil::Image colorerHeightMap(sil::Image image);

}
