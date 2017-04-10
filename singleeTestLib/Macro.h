//
//  Macro.h
//  ClothesMall
//
//  Created by yuchangsheng on 17/4/6.
//  Copyright © 2017年 encifang. All rights reserved.
//

#ifndef Macro_h
#define Macro_h


// 日志输出
#ifdef DEBUG
#define HHLog(...) NSLog(__VA_ARGS__)
#else
#define HHLog(...)
#endif

// 窗口
#define  kHHKeyWindow [[UIApplication sharedApplication] keyWindow]
//随机色
#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
/**  R G B A */
#define RGBA(R/*红*/, G/*绿*/, B/*蓝*/, A/*透明*/) [UIColor colorWithRed:R/255.f green:G/255.f blue:B/255.f alpha:A]

#define kScreenWidth  [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height

#define kNavgationH 44.0
#define kStatusBarH 20.0
#define kNavigationBarH 64
#define kTabBarH 49.0

//#define kNavigationBarColor RGBA(233, 84, 107, 1)
//#define kTableViewBgColor RGBA(245, 245, 245, 1)

#define kIPHONE5W 320.0
#define kIPHONE5H 568.0

#define kScaleW kScreenW / kIPHONE5W
#define kScaleH kScreenH / kIPHONE5H

#define kScaleX(x) x * kScaleW
#define kScaleY(y) y * kScaleH

#define kScaleMargin kScaleX(10)
#define kMargin 10

#define Font(size) [UIFont systemFontOfSize:size * kScaleW]

#define ClassWeak(weakClass) __weak typeof(self) weakClass = self

#define HHNotificationCenter [NSNotificationCenter defaultCenter]




#endif /* Macro_h */
