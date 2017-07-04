package bg.uni_sofia.fmi.Canny;

import java.awt.image.BufferedImage;
import java.io.IOException;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

import com.hopding.jrpicam.RPiCamera;
import com.hopding.jrpicam.exceptions.FailedToRunRaspistillException;

public class Canny {

	public static void main(String [ ] args)
	{
//		try {
//			RPiCamera piCamera = new RPiCamera("pi/Pictures");
//		piCamera.setToDefaults();
//		
//		BufferedImage image = piCamera.takeBufferedStill();
//		
//		} catch (FailedToRunRaspistillException e) {
//			e.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (InterruptedException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		  System.loadLibrary( Core.NATIVE_LIBRARY_NAME );
	      Mat mat = Mat.eye( 3, 3, CvType.CV_8UC1 );
	      System.out.println( "mat = " + mat.dump() );
	}
}
