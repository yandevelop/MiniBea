#import <Foundation/Foundation.h>

@protocol BeaSpotifyAPIHandlerDelegate <NSObject>
- (void)managerDidValidateAccessToken;
@end