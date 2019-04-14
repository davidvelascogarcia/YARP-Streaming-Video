//****************************************************
//****************************************************
//
//              YARP: Streaming Video
//
//              Tipo: Emisor
//
//              Autor: David Velasco García
//		       @davidvelascogarcia
//
//****************************************************
//****************************************************

// Librerias

#include <iostream>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <opencv2/opencv.hpp>
#include <yarp/sig/Image.h>


// Espacios de nombres

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace cv;
using namespace std;

int main()
{
    cout<< "Bienvenido al emisor de imágen en streaming vía YARP"<<endl;
    cout<<endl;
    cout<<endl;
    Network yarp;
    cout<<"Iniciando red de YARP..."<<endl;
    Port puerto_envio;  	
    cout<<"Iniciando cliente..."<<endl;
    cout<<"Abriendo puerto de envío con nombre /emisor_video"<<endl;
    puerto_envio.open("/emisor_video");
//    Network::connect("/emisor_video","/receptor_video");
    cout<<"Enviando fuentes de imágen.."<<endl;
    VideoCapture cap;

    if(!cap.open(0))
	cout << "Lo siento, no puedo acceder a la webcam, revise la conexión" << endl;
	while(true)
	{	
		Mat imagen;
		cap >> imagen;
		ImageOf<PixelBgr> B; 
   		B.setExternal(imagen.data,imagen.size[1],imagen.size[0]);
   		puerto_envio.write(B); 
}
    return 0;

}

// Envío de una imágen
/*
int main()
{
    cout<< "Bienvenido a Streaming de imágen vía YARP"<<endl;
    cout<<endl;
    cout<<endl;
    Network yarp;
    cout<<"Iniciando red de YARP"<<endl;
    Port puerto_envio;  	
    cout<<"Iniciando cliente..."<<endl;
    cout<<"Abriendo puerto de envío con nombre /image_output"<<endl;
    puerto_envio.open("/image_output");
    Network::connect("/image_output","/image_input");
    cout<<"Enviando imagen.."<<endl;
    Mat imagen = imread("/home/tiagoentrenamiento/Imágenes/37555905-25179878-29ef-11e8-9a2e-fe172ad7a162.jpg");
    ImageOf<PixelBgr> B; 
    B.setExternal(imagen.data,imagen.size[1],imagen.size[0]);
    puerto_envio.write(B); 
    return 0;
}
*/






