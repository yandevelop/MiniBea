#include <Foundation/Foundation.h>
#import "../MusicManager/BeaMusicManager.h"
#import "../../ViewControllers/SongSearchViewController/BeaSongSearchViewController.h"
#import "../../../TokenManager/BeaTokenManager.h"
#import "../../BeaSpotifyAPIHandlerDelegate.h"

@interface BeaSpotifyAPIHandler : NSObject
@property (nonatomic, weak) id<BeaSpotifyAPIHandlerDelegate> delegate;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *refreshToken;
@property (nonatomic, strong) NSNumber *expiryValue;
- (void)retrieveCurrentlyPlayingSong;
@end