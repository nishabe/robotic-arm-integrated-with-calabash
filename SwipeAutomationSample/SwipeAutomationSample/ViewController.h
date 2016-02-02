//
//  ViewController.h
//  SwipeAutomationSample
//

#import <UIKit/UIKit.h>
#import "DTDevices.h"

@interface ViewController : UIViewController <DTDeviceDelegate>
{
    BOOL cardReaderConnected;
}

@end

