//****************************************************
//****************************************************
//
//              YARP: Streaming Video
//
//              Tipo: Receptor
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
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/highgui.h>


// Espacios de nombres

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace cv;
using namespace std;

int main()
{
    cout<< "Bienvenido al streaming de imágen vía YARP, modo receptor"<<endl;
    cout<<endl;
    cout<<endl;
    Network yarp;
    cout<<"Iniciando red de YARP"<<endl;
    BufferedPort<ImageOf<PixelRgb> > port;
    port.open("/yarpStreamingVideo/img:i");
    cout<<"Esperando fuentes de imagen..."<<endl;

    while (true) {

       ImageOf<PixelRgb> *img = port.read();
       Mat in_cv = cv::cvarrToMat((IplImage *)img->getIplImage());
       Mat dest, gray;
       cvtColor(in_cv, gray, CV_BGR2GRAY);
       equalizeHist(gray, dest);
       CascadeClassifier detector;

	if(!detector.load("haarcascade_frontalface_alt.xml"))
		cout << "No se puede abrir clasificador." << endl;

	vector<Rect> rect;
	detector.detectMultiScale(dest, rect);

	for(size_t i = 0; i < rect.size(); i++ )
	{

	rectangle(in_cv,Point(rect[i].x, rect[i].y),Point(rect[i].x + rect[i].width, rect[i].y + rect[i].height),CV_RGB(0,255,0), 2);
	}

       cvtColor(in_cv, in_cv, CV_RGB2BGR);
       imshow("/yarpStreamingVideo/img:i",in_cv);
       if(waitKey(1) >= 0) break;
   }
    return 0;
}
