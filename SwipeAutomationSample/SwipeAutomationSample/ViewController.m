//
//  ViewController.h
//  SwipeAutomationSample
//

#import "ViewController.h"
static int currentTime=0;

@interface ViewController ()<DTDeviceDelegate>
@property (nonatomic,strong) DTDevices *lineaDevice;
@property (weak, nonatomic) IBOutlet UIView *cardReaderConnectionIndicator;
@property (weak, nonatomic) IBOutlet UILabel *time;
@property (weak, nonatomic) IBOutlet UILabel *message;
@property (weak,nonatomic)NSTimer *timer;
@property (assign) int count;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.count=16;
    [self startTimer];
    self.lineaDevice = [DTDevices sharedDevice];
    [self.lineaDevice addDelegate:self];
    [self.lineaDevice connect];
    [self enableSwipe];
}

- (void)enableSwipe
{
    NSError *error = nil;
    if (![self.lineaDevice msEnable:&error])
    {
        NSLog(@"msr enabled");
    }
    
}

-(void)startTimer{
    self.timer=[NSTimer scheduledTimerWithTimeInterval:1.0
                                                target:self
                                              selector:@selector(update)
                                              userInfo:nil
                                               repeats:YES];
    
}
//This delegate function is called when the device reads a Magnetic card data
- (void)magneticCardData:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3
{
    NSLog(@"magnetic card data -> :%@",track1);
    currentTime=self.count;
    [self.timer invalidate];
    NSString *cardTrack1 = [track1 copy];
    NSString *cardTrack2 = [track2 copy];
    
    NSString *cardHolderName = @"";
    NSString *cardAcountNumber = @"";
    NSString *cardExpiryYear = @"";
    NSString *cardExpiryMonth = @"";
    
    NSDictionary *cardData = [self.lineaDevice msProcessFinancialCard:cardTrack1 track2:cardTrack2];
    
    if(cardData)
    {
        cardHolderName = [[cardData objectForKey:@"cardholderName"] copy];
        cardAcountNumber = [[cardData objectForKey:@"accountNumber"] copy];
        cardExpiryYear = [[cardData objectForKey:@"expirationYear"] copy];
        cardExpiryMonth = [NSString stringWithFormat:@"%02d",[[cardData objectForKey:@"expirationMonth"] intValue]];
        
        NSString *details = [NSString stringWithFormat:@"%@|%@|%@|%@",cardHolderName,cardAcountNumber,cardExpiryYear,cardExpiryMonth];
        
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Card Details"
                                                            message:details
                                                           delegate:self
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
        self.count=16;
    }
    
}
- (void)alertView:(UIAlertView *)alertView
clickedButtonAtIndex:(NSInteger)buttonIndex{
    if (buttonIndex == [alertView cancelButtonIndex]){
        [self startTimer];
    }else{
        //TO DO
    }
}
-(void)update{
    self.count--;
    self.time.text=[NSString stringWithFormat:@"%d",self.count];
    switch (self.count) {
        case 15:
        {
            self.message.text
            =@"Swipe the card in the next 10 seconds";
        }
            break;
        case 5:
        {
            self.message.text
            =@"Tests will complete in 5 seconds";
            
        }
            break;
        case 0:
        {
            self.message.text
            =@"Automation tests completed";
        }
            break;
        case -1:
        {
            self.count=16;
            self.message.text
            =@"Restarting";
        }
            break;
        default:
            break;
    }
}
-(void)barcodeData:(NSString *)barcode type:(int)type {
    
    // You can use this data as you wish
    // Here I write barcode data into the console
    NSLog(@"Barcode Data: %@", barcode);
    
}

//This delegate function is called when connection state is changed

-(void)connectionState:(int)state
{
    switch (state)
    {
        case CONN_DISCONNECTED:
            cardReaderConnected = FALSE;
            self.cardReaderConnectionIndicator.backgroundColor=[UIColor grayColor];
            break;
            
        case CONN_CONNECTING:
            cardReaderConnected = FALSE;
            self.cardReaderConnectionIndicator.backgroundColor=[UIColor grayColor];
            break;
            
        case CONN_CONNECTED:
            cardReaderConnected = TRUE;
            self.cardReaderConnectionIndicator.backgroundColor=[UIColor greenColor];
            NSLog(@"The LP SDK Version is :%d",self.lineaDevice.sdkVersion);
            break;
    }
    
}
@end
