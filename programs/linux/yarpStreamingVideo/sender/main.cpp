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
    cout<<"Abriendo puerto de envío con nombre /yarpStreamingVideo/img:o"<<endl;
    puerto_envio.open("/yarpStreamingVideoSender");
    //    Network::connect("/yarpStreamingVideoSender/img:o","/yarpStreamingVideoSender/img:i","mjpeg",true);
    cout<<"Enviando fuentes de imágen.."<<endl;
    VideoCapture cap;
    Mat imagen;
    if(!cap.open(0))
	cout << "Lo siento, no puedo acceder a la webcam, revise la conexión" << endl;
	while(true)
	{	
		cap >> imagen;
		ImageOf<PixelBgr> B; 
   		B.setExternal(imagen.data,imagen.size[1],imagen.size[0]);
   		puerto_envio.write(B); 
}
    return 0;
}





