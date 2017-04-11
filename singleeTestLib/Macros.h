
//基本宏定义


/**
 调试
**/
#ifdef DEBUG
#define ALog(fmt, ...) NSLog(fmt, ##__VA_ARGS__)
//DEBUG  模式下打印日志,当前行
#define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#else
#define ALog(fmt, ...)
#define DLog(fmt, ...)
#define NSLog(...) {}
#endif


/**
 设备、界面
**/
#define kScreenWidth  [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight [[UIScreen mainScreen] bounds].size.height

#define kNavigationBarHeight             44
#define kStatusBarHeight                 20
#define kStatusAndNavBarHeight (kStatusBarHeight+kNavigationBarHeight)

// 是否iPad
#define isPad   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


/**
颜色
**/
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

#define hexColorA(rgbValue,a) [UIColor colorWithRed:((float)(((rgbValue) & 0xFF0000) >> 16))/255.0 green:((float)(((rgbValue) & 0xFF00)>>8))/255.0 blue: ((float)((rgbValue) & 0xFF))/255.0 alpha:(a)]

#define hexColor(hex) HexColorA(hex,1.0f)


/**
单例设置
**/

#define SINGLETON_INTERFACE(__class) +(__class *)sharedInstance;

#define SINGLETON_IMPLEMENTATION(__class)          \
+(__class *)sharedInstance {                     \
static dispatch_once_t once;                   \
static __class *__singleton__;                 \
dispatch_once(&once, ^{                        \
__singleton__ = [[[self class] alloc] init]; \
});                                            \
return __singleton__;                          \
}


/**
 版本比较
**/
// 当前版本
#define kSystemVersion          ([[UIDevice currentDevice] systemVersion])
#define kSystemVersionF          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define kSystemVersionD          ([[[UIDevice currentDevice] systemVersion] doubleValue])

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([kSystemVersion compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([kSystemVersion compare:v options:NSNumericSearch] != NSOrderedDescending)

// 是否大于等于IOS7
#define isIOS7                  ([systemVersionF >= 7.0)
// 是否大于等于IOS8
#define isIOS8                  ([systemVersionF >=8.0)
// 是否大于IOS9
#define isIOS9                  ([systemVersionF >=9.0)
// 是否大于等于某个版本
#define isIOS(version)          ([systemVersionF >= (version))


/**
文件目录
**/
#define kPathTemp                   NSTemporaryDirectory()
#define kPathDocument               [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kPathCache                  [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]


/**
常见主要单例
 **/
#define kApplication        [UIApplication sharedApplication]
#define kAppDelegate        [[UIApplication sharedApplication] delegate]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]



/**
语法糖
**/

//弱引用/强引用  可配对引用在外面用Weak_Self(self)，block用Strong_Self(self)  也可以单独引用在外面用Weak_Self(self) block里面用weakself
#define Weak_Self(type)  __weak typeof(type) weak##type = type;
#define Strong_Self(type)  __strong typeof(type) type = weak##type;


//时间戳
#define currentTime [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]]

//获取当前语言
#define currentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//判断委托响应
#define IS_DELEGATE_RSP_SEL(iDel, iSel) (iDel != nil && [iDel respondsToSelector:@selector(iSel)])

#define   locStr(str)   NSLocalizedString(str, nil)

