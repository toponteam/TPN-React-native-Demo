//
//  ATOfferSetting.h
//  AnyThinkSDK
//
//  Created by stephen on 26/8/2020.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ATModel.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATOfferTrackerExtraLifeCircleID;
extern NSString *const kATOfferTrackerExtraScene;

extern NSString *const kATOfferTrackerGDTClickID;
extern NSString *const kATOfferTrackerGDTWidth;
extern NSString *const kATOfferTrackerGDTHeight;
extern NSString *const kATOfferTrackerGDTDownX;
extern NSString *const kATOfferTrackerGDTDownY;
extern NSString *const kATOfferTrackerGDTUpX;
extern NSString *const kATOfferTrackerGDTUpY;
extern NSString *const kATOfferTrackerGDTRequestWidth;
extern NSString *const kATOfferTrackerGDTRequestHeight;

// For v5.7.7+ onlineApi. Some relative coordinates.
extern NSString *const kATOfferTrackerRelativeDownX;
extern NSString *const kATOfferTrackerRelativeDownY;
extern NSString *const kATOfferTrackerRelativeUpX;
extern NSString *const kATOfferTrackerRelativeUpY;
extern NSString *const kATOfferTrackerTimestamp;
extern NSString *const kATOfferTrackerMilliTimestamp;
extern NSString *const kATOfferTrackerEndTimestamp;
extern NSString *const kATOfferTrackerEndMilliTimestamp;
extern NSString *const kATOfferTrackerVideoTimePlayed;
extern NSString *const kATOfferTrackerVideoMilliTimePlayed;

// for v5.7.40+
extern NSString *const kATOfferTrackerKYAbsoluteCoord;
extern NSString *const kATOfferTrackerKYRelativeCoord;

// v5.7.42+
extern NSString *const kATOfferTrackerDeeplinkType;

extern NSString *const kATOfferTrackerOPDPType;

//typedef NS_ENUM(NSInteger, ATOfferCloseButtonSizeType) {
//    ATOfferCloseButtonSizeTypeNormal = 1,
//    ATOfferCloseButtonSizeType150Percent,
//    ATOfferCloseButtonSizeType75Percent,
//    ATOfferCloseButtonSizeType50Percent
//};

typedef NS_ENUM(NSInteger, ATAdShakeAnimationType) {
    ATAdShakeAnimationTypeRock = 1,
    ATAdShakeAnimationTypeJoggle = 2,
    ATAdShakeAnimationTypeShakeShake = 3,
};

typedef NS_ENUM(NSInteger, ATAdFormatType) {
    ATAdFormatTypeNative = 0,
    ATAdFormatTypeRewardedVideo = 1,
    ATAdFormatTypeBanner = 2,
    ATAdFormatTypeInterstitial = 3,
    ATAdFormatTypeSplash = 4
};

typedef NS_ENUM(NSInteger, ATOnlyDisplaySendWinType) {
    ATOnlyDisplaySendWinUnknownType = 0,
    ATOnlyDisplaySendWinOnType = 1,
    ATOnlyDisplaySendWinOffType = 2,
};

typedef NS_ENUM(NSInteger, ATRewardPictureAnimateType) {
    ATRewardPictureAnimateUnknownType = 0,
    ATRewardPictureNOAnimateType,
    ATRewardPictureClickAnimateType,
    ATRewardPictureRedPacketAnimateType,
    ATRewardPictureSlideAnimateType,
    ATRewardPictureCardScaleAnimateType,
};

typedef NS_ENUM(NSInteger, ATRewardPictureWebType) {
    ATRewardPictureWebJointType = 1,
    ATRewardPictureWebOtherType,
};


typedef NS_ENUM(NSInteger, ATBannerClickType) {
    ATBannerClickTypeTap = 1,
    ATBannerClickTypeInsideSlideTap,
    ATBannerClickTypeAllClick,
};

typedef NS_ENUM(NSUInteger, ATCtaAnimationType) {
    ATCtaAnimationTypeBreath = 1,// 呼吸
    ATCtaAnimationTypeSway,// 中心点摆动
    ATCtaAnimationTypeStreak,// 斜边划过
};

typedef NS_ENUM(NSInteger, ATDirectOfferUnitType) {
    ATDirectOfferUnitPictureType = 0,
    ATDirectOfferUnitVideoType = 1,
};

typedef NS_ENUM(NSUInteger, ATVideoPlaySetting) {
    ATVideoPlayAlwaysAutoPlaySetting  = 0,
    ATVideoPlayOnlyWiFiAutoPlaySetting,
    ATVideoPlayClickAutoPlaySetting,
};

@class ATGuideClickOverlayItem;
@interface ATOfferSetting : ATModel
-(instancetype) initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) ATAdShakeAnimationType adShakeAnimationType;
@property(nonatomic, readwrite) NSString *placementID;
@property(nonatomic, readwrite) ATAdFormatType format;
@property(nonatomic, readwrite) ATVideoClickable videoClickable;
@property(nonatomic, readwrite) NSTimeInterval resourceDownloadTimeout;
@property(nonatomic, readwrite) NSTimeInterval bannerAppearanceInterval;
@property(nonatomic, readwrite) NSTimeInterval bannerDisapearInterval;
@property(nonatomic, readwrite) ATEndCardClickable endCardClickable;
@property(nonatomic, readwrite) BOOL unMute;
@property(nonatomic, readwrite) NSTimeInterval closeButtonAppearanceInterval;
@property(nonatomic, readwrite) ATLoadStorekitTime storekitTime;
@property(nonatomic, readwrite) NSInteger lastOfferidsNum;

// The inherent attributes of the ad, such as the version number, etc.
//@property(nonatomic, readwrite) BOOL showAdAttrs;

//setting for banner
@property(nonatomic, readwrite) NSString *bannerSize;
@property(nonatomic, readwrite) BOOL showBannerCloseBtn;
@property(nonatomic, readwrite) NSInteger splashCountDownTime;
@property(nonatomic, readwrite) BOOL skipable;
@property(nonatomic, readwrite) NSInteger splashOrientation;

@property(nonatomic, readwrite) ATOfferLayoutType layoutType;
@property(nonatomic, readwrite) ATClickMode clickMode;
@property(nonatomic, readwrite) ATLoadType loadType;
@property(nonatomic, readwrite) ATUserAgentType impressionUAType;
@property(nonatomic, readwrite) ATUserAgentType clickUAType;
@property(nonatomic, readwrite) ATDeepLinkClickMode deeplinkClickMoment;
@property(nonatomic, readwrite) ATSplashType splashType;
@property(nonatomic, readwrite) ATSplashImageScaleType splashImageScaleType;

/// The minimum value of the close button delayed display
@property(nonatomic) NSInteger closeBtnDelayMinTime;
/// The maximum value of the close button delayed display
@property(nonatomic) NSInteger closeBtnDelayMaxTime;

@property(nonatomic) NSInteger closeBtnDelayRate;

// v5.7.56+
@property(nonatomic) CGFloat closeBtnNoFirstClickArea;

@property(nonatomic) CGFloat closeBtnFirstClickArea;

@property(nonatomic) CGFloat closeBtnNoFirstClickAreaScal;

@property(nonatomic) CGFloat closeBtnFirstClickAreaScal;

@property (nonatomic, assign) BOOL isGuideClick;

@property(nonatomic) NSInteger onRewardTime;
@property(nonatomic) BOOL rewardWhenFailed;

@property(nonatomic) BOOL showEendCard;

// Whether to enable the shake function. 1 means open, 2 means not open
@property(nonatomic) BOOL splashShakeSw;

// The minimum value of the gyroscope that can trigger a shake click. Default is 0.1
@property(nonatomic, assign) CGFloat shakeStrength;

// Shake the time interval that a tap can trigger again. The default is 5s
@property(nonatomic,assign) NSInteger shakeTime;

@property (nonatomic,assign) NSTimeInterval clickCacheTime;
@property (nonatomic,assign) BOOL clickNotice;

//6.1.32https://confluence.magicgame001.com/pages/viewpage.action?pageId=47126246
@property (nonatomic, assign) BOOL overlaySwitch;
@property (nonatomic, assign) NSTimeInterval overlayDuration;
@property (nonatomic, assign) NSTimeInterval overlayShowTime;
@property (nonatomic, assign) BOOL overlayUserDismissible;
@property (nonatomic, assign) BOOL storeKitSwitch;
@property (nonatomic, assign) NSTimeInterval monitoringShowTime;

///是否预加载Mraid素材，yes是预加载，no是不预加载
@property (nonatomic, assign) BOOL mraidPreLoadSwitch;
/// 是否失败重发networkTK
@property (nonatomic, assign) BOOL retryNetworkTkSwitch;

/// 仅在展示时发送Win
@property (nonatomic, assign) ATOnlyDisplaySendWinType onlyDisplaySendWinType;

/// 自动点击 6.2.2_5
@property (nonatomic, assign) BOOL isAutoClickImage;
@property (nonatomic, assign) NSTimeInterval autoClickImageTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickImageTriggerDuration;

@property (nonatomic, assign) BOOL isAutoClickVideo;
@property (nonatomic, assign) NSTimeInterval autoClickVideoTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickVideoTriggerDuration;

@property (nonatomic, assign) BOOL isAutoClickEndCard;
@property (nonatomic, assign) NSTimeInterval autoClickEndCardTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickEndCardTriggerDuration;

@property (nonatomic, assign) ATRewardPictureAnimateType rewardPictureAnimateType;
@property (nonatomic, assign) NSTimeInterval rewardPictureOnRewardDuration;
@property (nonatomic, assign) ATRewardPictureWebType rewardPictureWebType;

@property (nonatomic, assign) ATBannerClickType bannerTriggerClickType;

@property (nonatomic, assign) ATAdOfferInterType interType;
@property (nonatomic, assign) ATDirectOfferUnitType unitType;

// click guide animation Switch
@property (nonatomic, assign) BOOL guideClickOverlaySwitch;
// click guide animation list
@property (nonatomic, strong) NSArray<ATGuideClickOverlayItem *> *overlayItemArray;
// Q&A pop-up option answer
@property (nonatomic, strong) NSString *qaAnswerText;
// The probability of an invalid close button
@property (nonatomic, assign) BOOL closeButtonInvalidSwitch;

@property (nonatomic, assign) BOOL enableInterstitialStyleEnvelope;
@property (nonatomic, assign) BOOL isImpressionInterstitialStyleEnvelope;

/// 摇一摇图标外面的文案
@property (nonatomic, strong) NSString *shakeText;
/// 摇一摇图标里面的文案
@property (nonatomic, strong) NSString *shakeInternalText;
/// 摇一摇缩小后文案
@property (nonatomic, strong) NSString *shakeSmallText;
/// 摇一摇图片URL字符串
@property (nonatomic, strong) NSString *shakeImageURLString;
@property (nonatomic, assign) BOOL isShowDetentionPage;
/// 开屏结束弹窗倒计时 当下发为0的时，全屏开屏结束后不展示弹窗
@property (nonatomic, assign) NSTimeInterval splashPopTime;
/// 视频播放N秒后出现Banner(顶部)
@property (nonatomic, assign) NSTimeInterval topBannerStartTime;
/// Banner弹出播放时长(顶部)
@property (nonatomic, assign) NSTimeInterval topBannerShowTime;

/// 开屏 控制广告点击跳转后，是否销毁广告
@property (nonatomic, assign) BOOL isClickCloseAd;
/// 开屏倒计时结束后， 视频是否继续播放 1-是,2-否, 默认：2 
@property (nonatomic, assign) BOOL countDownPlaySwitch;

// offer 维度 readyRate
@property (nonatomic, assign) NSInteger readyRate;
///表示video下载到ready rate后是否继续下载，1或不下发表示继续下载，2表示暂停下载。默认不下发
@property (nonatomic, assign) NSInteger videoContinueType;
///表示视频展示后，观看到多少比例开始继续下载（针对边下边播场景）。默认0或不下发表示开始播放就开始下载。
@property (nonatomic, assign) NSInteger cdRate;
// 1:部分下载；2:下载剩余全部
@property (nonatomic, assign) NSInteger particalDownloadState;

@property (nonatomic, assign) ATCtaAnimationType ctaAnimationType;

/// 原生视频自动播放设置，目前仅adx支持配置
@property (nonatomic, assign) ATVideoPlaySetting videoPlaySetting;

- (BOOL)isExistRewardPictureAnimate;

- (CGFloat)getClickArea:(NSInteger)sizeType;
- (CGFloat)getClickAreaScal:(NSInteger)sizeType;

@end

NS_ASSUME_NONNULL_END
