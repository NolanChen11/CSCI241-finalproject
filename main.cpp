//read image and transform it into array of pixels.
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <random>
using std::cout;
using std::endl;
using namespace cv;

int similar(int dv,Vec3b c,Vec3b standard){
    if(standard[0]-dv<c[0]&&standard[0]+dv>c[0]){
        if(standard[1]-dv<c[1]&&standard[1]+dv>c[1]){
            if(standard[2]-dv<c[2]&&standard[2]+dv>c[2]){
                return 1;
            }
        }
    }
    return 0;
}
int r(int range){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(range-30, range);
    return distr(eng);
}
void drawCircle(Mat img,Point center,int b,int g, int r){
    double thick=1;
    int line=8;
    circle(img,center,20,Scalar(r,g,b),thick,line);
}

int main(int argc, char *argv[]){
    std::vector<Vec3b> standard;
    Vec3b skin;
    skin[0]=133;skin[1]=140;skin[2]=197;
    standard.push_back(skin);
    skin[0]=180;skin[1]=188;skin[2]=236;
    standard.push_back(skin);
    skin[0]=164;skin[1]=163;skin[2]=209;
    standard.push_back(skin);
    skin[0]=94;skin[1]=102;skin[2]=161;
    standard.push_back(skin);
    skin[0]=53;skin[1]=51;skin[2]=80;
    standard.push_back(skin);
    //vector<int> choice;
    
    /*standard[0][0]=197;standard[0][1]=140;standard[0][2]=133;
    standard[1][0]=236;standard[1][1]=188;standard[1][2]=180;
    standard[2][0]=209;standard[2][1]=163;standard[2][2]=164;
    */
    if (argc != 2) {
        cout << "Expecting a image file to be passed to program" << endl;
        return -1;
    }
    
    //cv::Mat img = cv::imread(argv[1]);
    Mat image=imread(argv[1]);
    if (image.empty()) {
        cout << "Not a valid image file" << endl;
        return -1;
    }
    Mat hsv;
    cvtColor(image,hsv,COLOR_BGR2HSV);
    //unsigned char *imgarray = (unsigned char*)(img.data);
    cout << image.cols << endl;
    /*
    for(int i=0;i<5;i++){
        int total=0;
        for(int y=0;y<image.rows;y++){
            for(int x=0;x<image.cols;x++){
            Vec3b color = image.at<Vec3b>(Point(x,y));
                if(similar(20,color,standard[i])==1){
                    cout << "enterif" << endl;
                    color[0]=255;
                    color[1]=255;
                    color[2]=255;
                    
                }
                image.at<Vec3b>(Point(x,y)) = color;
            }
        }
    }*/
    Mat dst;
    inRange(hsv,Scalar(0,0.28*255,0),Scalar(25,0.68*255,255),dst);
    Mat out;
    image.copyTo(out,dst);
    Mat Display= Mat::zeros( dst.rows, dst.cols, CV_8UC3 );;
    /*
    for(int y=0;y<out.rows;y=y+10){
            for(int x=0;x<out.cols;x=x+10){
                Vec3b outcolor = out.at<Vec3b>(Point(x,y));
                    
                    if(outcolor[0]!=0&&outcolor[1]!=0&&outcolor[2]!=0){
                        int ran=outcolor[0]+outcolor[1]+outcolor[2];
                        if(ran<96){
                            drawCircle(Display,Point(x,y),r(30),r(30),r(30));
                        }else if(ran<192){
                            int random=r(50);
                            drawCircle(Display,Point(x,y),r(50),r(50),r(50));
                        }else if(ran<288){
                            int random=r(80);
                            drawCircle(Display,Point(x,y),r(80),r(80),r(80));
                        }else if(ran<384){
                            int random=r(110);
                            drawCircle(Display,Point(x,y),r(110),r(110),r(110));
                        }else if(ran<480){
                            int random=r(140);
                            drawCircle(Display,Point(x,y),r(140),r(140),r(140));
                        }else if(ran<576){
                            drawCircle(Display,Point(x,y),r(170),r(170),r(170));
                        }else if(ran<672){
                            drawCircle(Display,Point(x,y),r(200),r(200),r(200));
                        }else{
                            drawCircle(Display,Point(x,y),r(230),r(230),r(230));
                        }
                        
                    }else{
                       drawCircle(Display,Point(x,y),255,255,255);
                    }
                   

            }
    }
    */

    for(int y=0;y<out.rows;y=y+10){
            for(int x=0;x<out.cols;x=x+10){
                Vec3b outcolor = out.at<Vec3b>(Point(x,y));
                    
                    if(outcolor[0]!=0&&outcolor[1]!=0&&outcolor[2]!=0){
                        int ran=outcolor[0]+outcolor[1]+outcolor[2];
                        if(ran<96){
                            drawCircle(Display,Point(x,y),240,139,20);
                        }else if(ran<192){
                            int random=r(50);
                            drawCircle(Display,Point(x,y),230,180,30);
                        }else if(ran<288){
                            int random=r(80);
                            drawCircle(Display,Point(x,y),210,210,80);
                        }else if(ran<384){
                            int random=r(110);
                            drawCircle(Display,Point(x,y),150,150,200);
                        }else if(ran<480){
                            int random=r(140);
                            drawCircle(Display,Point(x,y),110,170,200);
                        }else if(ran<576){
                            drawCircle(Display,Point(x,y),110,200,200);
                        }else if(ran<672){
                            drawCircle(Display,Point(x,y),50,100,200);
                        }else{
                            drawCircle(Display,Point(x,y),0,80,240);
                        }
                        
                    }else{
                       drawCircle(Display,Point(x,y),255,255,255);
                    }
                   

            }
    }
   /*
   for(int y=0;y<out.rows;y=y+10){
            for(int x=0;x<out.cols;x=x+10){
                Vec3b outcolor = out.at<Vec3b>(Point(x,y));
                    
                    if(outcolor[0]!=0&&outcolor[1]!=0&&outcolor[2]!=0){
                        int ran=outcolor[0]+outcolor[1]+outcolor[2];
                        if(ran<96){
                            drawCircle(image,Point(x,y),r(20),r(20),r(20));
                        }else if(ran<192){
                            int random=r(50);
                            drawCircle(image,Point(x,y),r(50),r(50),r(50));
                        }else if(ran<288){
                            int random=r(80);
                            drawCircle(image,Point(x,y),r(80),r(80),r(80));
                        }else if(ran<384){
                            int random=r(110);
                            drawCircle(image,Point(x,y),r(110),r(110),r(110));
                        }else if(ran<480){
                            int random=r(140);
                            drawCircle(image,Point(x,y),r(140),r(140),r(140));
                        }else if(ran<576){
                            drawCircle(image,Point(x,y),r(170),r(170),r(170));
                        }else if(ran<672){
                            drawCircle(image,Point(x,y),r(200),r(200),r(200));
                        }else{
                            drawCircle(image,Point(x,y),r(230),r(230),r(230));
                        }
                        
                    }else{
                       drawCircle(Display,Point(x,y),255,255,255);
                    }
                   

            }
    }
    */
    /*
    for(int y=0;y<out.rows;y++){
            for(int x=0;x<out.cols;x++){
                Vec3b outcolor2 = out.at<Vec3b>(Point(x,y));
                if(outcolor2[0]==0&&outcolor2[1]==0&&outcolor2[2]==0){
                    outcolor2[0]=255;outcolor2[1]=255;outcolor2[2]=255;
                    Display.at<Vec3b>(Point(x,y)) = outcolor2;
                }

            }
    }*/
    imwrite("image11.JPG",dst);
    imshow("image.JPG",dst);
    imwrite("final13.JPG",Display);
    imshow("final.JPG",Display);
    waitKey(0);
    return 0;
}
 
