//
//  UMessage.h
//  ReflectTest
//
//  Created by yangyanxiang on 16/9/7.
//  Copyright © 2016年 yangyanxiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UMessage.h>
#import <UIKit/UIApplication.h>


#define UMSYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define _IPHONE80_ 80000
@interface UMessagePushUtil : NSObject<UIAlertViewDelegate>
@property(nonatomic,weak) UIViewController* _umUtilCurViewController; //记录当前页面
@property(nonatomic,retain) NSString *_storyboardName;
@property(nonatomic,retain) NSDictionary* _userInfo;

/**
 * @desc 功能:在AppDelegate::didFinishLaunchingWithOptions里调用，初始化友盟推送
 * @param AppKey: Umeng AppKey
 * @param storyboardName: 故事板名字
 * @param launchOptions: AppDelegate::didFinishLaunchingWithOptions中的launchOptions
 */
-(void) initWithUmengAppKey:(NSString*) AppKey storyboardName:(NSString*)storyboardName launchOptions: (NSDictionary *) opts;


/**
 * @desc 功能:在AppDelegate::didRegisterForRemoteNotifications里调用，若有别名设置别名
 * @param deviceToken: AppDelegate::didRegisterForRemoteNotifications中的deviceToken
 * @param aliasName: Umeng中为用户设置的别名
 * @param aliasType: 别名类型
 */
- (void) didRegisterForRemoteNotifications:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken aliasName: (NSString*)alias aliasType:(NSString*)type;


/**
 * @desc 功能:在AppDelegate::didReceiveRemoteNotification里调用，收到远程退送消息时自动调用
 * @param userInfo: AppDelegate::didReceiveRemoteNotification中的userInfo
 */
- (void) didReceiveRemote:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;



/**
 *  @desc 功能: 在AppDelegate::didFailToRegisterForRemoteNotificationsWithError中调用，处理远程消息获取时的错误
 *  @param didFailToRegisterForRemoteNotificationsWithError:AppDelegate::didFailToRegisterForRemoteNotificationsWithError中收到的错误信息
 */
- (void) didFailToRegisterForRemote:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;



/**
 * @desc 功能:辅助方法，用来添加别名，一般不用自己调用
 * @param alias:别名
 * @param aliasType:别名类型
 */
- (void) addAlias:(NSString*)alias aliasType:(NSString*)type;



/**
 * @desc 功能:辅助方法，为用户添加标签
 * @param tags:标签
 */
- (void) addTags:(id)tags;



/**
 * @desc 功能:辅助方法，解析退送传来的远程参数根据参数进行跳转，一般不需要用户主动调用
 * @param userInfo:远程传入的参数
 * @param storyboardName:故事板名
 */
- (void) jumpWithRemoteNotification:(NSDictionary *)userInfo storyboardName:(NSString*)storyboardName;



/**
 * @desc 功能:辅助方法，一般不用自己调用
 */
- (void) registeViewController:(UIViewController*)vc;



/**
 * @desc 功能:辅助方法，一般不用自己调用
 */
- (void) removeViewController;



/**
 * @desc 功能:辅助方法，一般不用自己调用
 */
-(void) notification_remote_push;



/**
 * @desc 功能:辅助方法，一般不用自己调用
 */
-(void) jumpcenterWhenOpenApp;



/**
 * @desc 功能: App打开的情况下弹出提示框，App关闭的情况下启动时直接跳转
 * @param from:
 *              0 直接跳转
 *              1 UIalert
 */
- (void) jumpFrom:(NSUInteger)from userInfo:(NSDictionary *)userInfo;


/**
 * @desc 功能:单例
 */
+(id) SharedUMPushUtil;
@end


