#include <Foundation/Foundation.h>

@interface BeaTokenManager : NSObject
+ (instancetype)sharedInstance;
@property (nonatomic, strong) NSString *BRAccessToken;
@property (nonatomic, strong) NSDictionary *headers;
@property (nonatomic, strong) NSString *spotifyAccessToken;
@property (nonatomic, strong) NSString *spotifyRefreshToken;
@property (nonatomic, strong) NSNumber *expiryValue;
- (void)writeToKeychainWithDictionary:(NSDictionary *)response;
- (void)retrieveCredentials;
@end