//****************************************************
//****************************************************
//
//              YARP: Streaming Control Windows
//
//              Tipo: Emisor
//
//              Autor: David Velasco García
//		        @davidvelascogarcia
//
//****************************************************
//****************************************************

// Librerias
#include "stdafx.h"
#include <iostream>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <yarp/sig/all.h>
#include <yarp/sig/Image.h>


// Espacio de nombres
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace std;
using namespace cv;

int main()
{
	cout << "Bienvenido al emisor de imágen en streaming vía YARP" << endl;
	cout << endl;
	cout << endl;
	Network yarp;
	cout << "Iniciando red de YARP..." << endl;
	Port puerto_envio;
	cout << "Iniciando cliente..." << endl;
	cout << "Abriendo puerto de envío con nombre /emisor_video" << endl;
	puerto_envio.open("/emisor_video");
	Network::connect("/emisor_video", "/receptor_video");
	cout << "Enviando fuentes de imágen.." << endl;
	VideoCapture cap;

	if (!cap.open(0))
		cout << "Lo siento, no puedo acceder a la webcam, revise la conexión" << endl;
	while (true)
	{
		Mat imagen;
		cap >> imagen;
		ImageOf<PixelBgr> B;
		B.setExternal(imagen.data, imagen.size[1], imagen.size[0]);
		puerto_envio.write(B);
	}
	return 0;

}
