#import <UIKit/UIKit.h>
#import "../Downloader/BeaDownloader.h"

@interface BeaButton : UIButton
+ (instancetype)downloadButton;
- (void)toggleVisibilityWithGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;
@end