#import <UIKit/UIKit.h>
#import "../../Managers/MusicManager/BeaMusicManager.h"
#import "../../../TokenManager/BeaTokenManager.h"

@interface BeaSongSearchViewController : UIViewController <UISearchBarDelegate, UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UISearchBar *searchBar;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *searchResults;
@property (nonatomic, strong) UIView *contentContainer;
@property (nonatomic, strong) NSCache *imageCache;
@end