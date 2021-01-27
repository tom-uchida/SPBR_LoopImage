#ifndef Create_Loop_Image_HH
#define Create_Loop_Image_HH

#include <kvs/RotationMatrix33>
#include <kvs/ObjectManager>

class sc : public kvs::glut::Screen
{

private:
    const double end_rotate_angle = 360.0;
    const int num_of_Image = 180;
    // const int num_of_Image = 360;

    //enum ROTATEAXIS{XROTATE, YROTATE, ZROTATE}axis = ZROTATE; // Z軸周り
    enum ROTATEAXIS{XROTATE, YROTATE, ZROTATE}axis = YROTATE; // Y軸周り

public:
    sc( kvs::glut::Application* application = 0 )
    :kvs::glut::Screen(application){};

    void paintEvent( void )
    {
        double s_loop = end_rotate_angle / (double)num_of_Image;
        kvs::Matrix33f Rot;    
        if ( axis == XROTATE )
            Rot = kvs::Matrix33f::RotationX( s_loop );
        else if ( axis == YROTATE )
            Rot = kvs::Matrix33f::RotationY( s_loop );
        else
            Rot = kvs::Matrix33f::RotationZ( s_loop );

        std::cout << "\nNow generating series of images..." << std::endl;
        for ( int i = 0; i < num_of_Image; i++ ) {      
            scene()->objectManager()->rotate( Rot );

            kvs::glut::Screen::paintEvent();
            kvs::ColorImage snapshot_image;
            snapshot_image = scene()->camera()->snapshot();
            std::string o_filename( "IMAGE_DATA/image" );
            char s[5];
            sprintf( s, "%03d", i );
            o_filename += s;
            o_filename += ".bmp";
            snapshot_image.write( o_filename );
        }
        std::cout << "Done!(PATH: ./IMAGE_DATA/imageXXX.bmp)\n" << std::endl;

        exit(0);
    }
    //----
};

#endif