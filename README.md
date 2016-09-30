#IOS集成UmengPushDemo
###1.安装 UMengMessage SDK
` Podfile:
	platform :ios, '7.0'
	source 'https://github.com/CocoaPods/Specs.git'
	inhibit_all_warnings!
	target 'ReflectTest' do
    pod 'iOS-UMengMessage', '~> 1.2.5'
	end
	`
###2.初始化UmengPush
* 在AppDelegate.m中引入UMessagePushUtil.h: import "UMessagePushUtil.h"
* 在` - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions `中调用` [[UMessagePushUtil SharedUMPushUtil] initWithUmengAppKey:umengAppId storyboardName:@"Main" launchOptions:launchOptions];`umengAppId为友盟的AppKey,storyboardName为故事板名字。

###3.设置别名
* 则在 ` - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken `中添加` [[UMessagePushUtil SharedUMPushUtil] didRegisterForRemoteNotifications:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken aliasName:aliasName aliasType:aliasType];`aliasType为别名类型，aliasName为别名。

###4.跳转页面设置
* 在所有需要跳转的ViewController引入UIViewController+PushInfo.h: ` import "UIViewController+PushInfo.h" `
* 当重写 ` -(void)viewWillAppear:(BOOL)animated;-(void)viewDidAppear:(BOOL)animated; ` 和 `-(void)viewDidDisappear:(BOOL)animated;`时，需调用`[super methodXXX]`。


###5.友盟传参示例：
* key: data
* value:`{"class":"CustomerVC","instancefrom":"storyboard","method":"updateWithModel","propertys":{"type":"model","modelname":"UserModel","value":{"_name":"用户01","_tocken":"010","_age":25}}} `

``` 
	示例模型：
	@interface UserModel : NSObject
		@property(nonatomic,retain) NSString *_name;
		@property(nonatomic,retain) NSString *_tocken;
		@property(nonatomic) NSInteger _age;
	 @end 
	示例跳转的目标页面：
	@interface CustomerVC : UIViewController
		@property (weak, nonatomic) IBOutlet UILabel *_nameLabel;
		@property (weak, nonatomic) IBOutlet UILabel *_tockenLabel;
		@property (weak, nonatomic) IBOutlet UILabel *_ageLabel;
		-(void) updateWithModel:(UserModel*)model;
	@end
```

参数 | 说明 | 
------------ | ------------- | 
class | 跳转到的目标页面  | 
instancefrom| storyboard：从故事板构造 code: 通过代码生成 |
method| 目标页面赋值方法名 |
propertys::type| 参数模型中参数类型，有number dict array model |
propertys::value| ①type为number或dict或array时为相应数值(dict转为JSON串)，②type为model时为模型中字段和字段值组成的JSON串|
propertys::modelname| 目标页面赋值时传递的模型名 | 
