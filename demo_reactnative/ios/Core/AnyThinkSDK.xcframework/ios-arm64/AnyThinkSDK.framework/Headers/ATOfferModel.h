//
//  ATOfferModel.h
//  AnyThinkSDK
//
//  Created by stephen on 21/8/2020.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import "ATModel.h"
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATOfferBannerSize320_50;
extern NSString *const kATOfferBannerSize320_90;
extern NSString *const kATOfferBannerSize300_250;
extern NSString *const kATOfferBannerSize728_90;

@interface ATVideoPlayingTKItem : NSObject

@property (nonatomic, copy) NSArray<NSString *> *urls;
@property (nonatomic) NSInteger triggerTime;
@property (nonatomic) BOOL sent;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

#define ATADCTATAG 10000
#define ATADTEXTTAG 10001
#define ATADTITLETAG 10002
#define ATADICONTAG 10003
#define ATADSHAKETAG 10004
#define ATADWEBTAG 10005
#define ATADCTABACKTAG 10006
#define ATADMAINIMAGETAG 10007
#define ATADMEDIAVIEWTAG 10008
#define ATADDOMAINTAG 10009
#define ATADLOGOTAG 100010
#define ATADSPLASHENDPOPTAG 2023101301
#define ATADRATINGTAG 2023102501
#define ATADADVERTISERTAG 2023102502

//#define ATADSPLASHENDPOPSHAKETAG 2023101302

// v5.7.24
typedef NS_ENUM(NSInteger, ATOfferInterActableArea) {
    ATOfferInterActableAreaAll,
    ATOfferInterActableAreaVisibleItems,
    ATOfferInterActableAreaCTA
};

@class ATCampaignExp;
@class ATAdWebViewManager;

typedef NS_ENUM(NSUInteger, ATOfferModelResourceType) {
    ATOfferModelResourceTypeVideo,
    ATOfferModelResourceTypeImage,
    ATOfferModelResourceTypeAudio,
};

typedef NS_ENUM(NSUInteger, ATCoordinateModeType) {
    ATCoordinateModeTypeRandom = 1,
    ATCoordinateModeTypeFixationCode,
    ATCoordinateModeTypeNotReplace,
};



@interface ATOfferModel : ATModel
/// 当SK加载失败,直接跳转appStore 链接
@property (nonatomic, copy) NSString *appStoreUrlString;

/// html 广告宽
@property (nonatomic, assign) NSInteger offerBannerW;
/// html 广告高
@property (nonatomic, assign) NSInteger offerBannerH;

/// offermodel的唯一标识，在初始化时SDK默认生成
@property(nonatomic, copy) NSString *offerIdentifier;
@property(nonatomic, copy) NSString *requestID;

@property(nonatomic, assign) ATOfferInterActableArea interActableArea;
@property(nonatomic, copy) NSString *resourceID;
@property(nonatomic, copy) NSString *unitID;
@property(nonatomic, copy) NSString *offerID;
@property(nonatomic, copy) NSString *offerDspID;
@property(nonatomic, copy) NSString *pkgName;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *text;
@property(nonatomic, assign) NSInteger rating;
@property(nonatomic, copy) NSString *iconURL;
@property(nonatomic, copy) NSString *fullScreenImageURL;
@property(nonatomic, assign) ATInterstitialType interstitialType;//check the offer for video or image
@property(nonatomic, copy) NSString *logoURL;//adv_u
@property(nonatomic, copy) NSString *CTA;
@property(nonatomic, copy) NSString *videoURL;
@property(nonatomic, copy) NSString *storeURL;
@property(nonatomic, assign) ATLinkType linkType;
@property(nonatomic, copy) NSString *clickURL;
@property(nonatomic, copy) NSString *deeplinkUrl;
@property(nonatomic, copy) NSString *localResourceID;
@property(nonatomic, assign) ATOfferModelType offerModelType;
@property(nonatomic, assign) ATOfferCrtType crtType;

@property(nonatomic, copy) NSString *jumpUrl;
@property(nonatomic, assign) NSInteger offerFirmID;


@property(nonatomic, assign) BOOL offerIMCapSw;
@property(nonatomic, assign) BOOL offerCLCapSw;

@property(nonatomic, assign) BOOL resourceIMCapSw;
@property(nonatomic, assign) BOOL resourceCLCapSw;



// ad attributes
@property(nonatomic, copy) NSString *adPublisher;
@property(nonatomic, copy) NSString *adVersion;
@property(nonatomic, copy) NSString *adPrivacy;
@property(nonatomic, copy) NSString *adPermission;

//banner(myoffer:5.6.6)
@property(nonatomic, copy) NSString *bannerImageUrl;
@property(nonatomic, copy) NSString *bannerBigImageUrl;
@property(nonatomic, copy) NSString *rectangleImageUrl;
@property(nonatomic, copy) NSString *homeImageUrl;

@property(nonatomic, strong) NSArray<NSString*>* resourceURLs;
@property(nonatomic, strong) NSArray<NSString*>* resourceImageURLs;
@property(nonatomic, strong) NSArray<NSString*>* resourceAudioURLs;

@property(nonatomic,assign) NSInteger displayDuration;

@property(nonatomic, strong) NSArray<NSString*>* clickTKUrl;
@property(nonatomic, strong) NSArray<NSString*>* openSchemeFailedTKUrl;

//to do
@property(nonatomic,assign) NSInteger videoCurrentTime;
@property(nonatomic,assign) NSInteger videoResumeTime;

@property(nonatomic, strong,nullable) NSDictionary *tapInfoDict;

// If it is YES, it means that the feedback has been done.
@property(nonatomic,assign) BOOL feedback;

// v5.7.47 +
@property(nonatomic, strong) NSArray<NSString*>* deeplinkSuccessUrl;
@property(nonatomic, strong) NSDictionary* at_deeplinkSuccessUrl;
@property(nonatomic, strong) NSArray<NSString*>* deeplinkStartTKUrl;
@property(nonatomic, strong) NSDictionary* at_deeplinkStartTKUrl;

// v5.7.56+
@property(nonatomic, assign) ATSplashImageScaleType splashImageScaleType;

// Whether to enable the shake function. 1 means open, 2 means not open
@property(nonatomic,assign) BOOL splashShakeSw;

// The minimum value of the gyroscope that can trigger a shake click. Default is 0.1
@property(nonatomic, assign) CGFloat shakeStrength;

// Shake the time interval that a tap can trigger again. The default is 5s
@property(nonatomic,assign) NSInteger shakeTime;

@property(nonatomic,assign) BOOL canMute;

// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
@property(nonatomic, assign) NSInteger format;

// for SKAdNetwork
@property (nonatomic, strong) ATCampaignExp *campaignExp;

//6.1.32https://confluence.magicgame001.com/pages/viewpage.action?pageId=47126246
@property (nonatomic, assign) BOOL storeKitSwitch;

@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *urlJavascriptDic;

@property (nonatomic, assign) NSInteger networkFirmID;

- (BOOL)showAdAttributes;

@property (nonatomic, assign) BOOL isGuideClick;

@property (nonatomic, strong) ATAdWebViewManager *adWebManager;

// 标记广告协议 0: 默认，1:Mraid，2:Vast
@property(nonatomic, assign) ATOfferAdpType adpType;

/// 微信小程序ID
@property (nonatomic, copy) NSString *wxUserName;

/// 打开微信小程序的路径
@property (nonatomic, copy, nullable) NSString *wxPath;

/// 素材是否来源于bid
@property (nonatomic, assign) BOOL isFodderSourceBid;

// 视频文件大小，MB
@property (nonatomic, assign) double videoSize;

@property (nonatomic, assign) BOOL splashVideoPlayFinishCloseSw;
/// 坐标回传模式
/// 1-非真实点击随机坐标：以前的逻辑（6.3.30及以上默认值）
/// 2-非真实点击-999：非真实点击时，坐标替换-999
/// 3-非真实点击不换坐标：非真实点击时，删掉宏不更换坐标
@property (nonatomic, assign) ATCoordinateModeType coordinateModeType;


- (NSString *_Nullable)getResourceURLkey:(NSString *_Nullable)urlStr;

#pragma mark - 素材缺少判断
- (BOOL)isLoseAll;

- (BOOL)isShowAllUI;

- (BOOL)isLoseIcon;

- (BOOL)isLoseTitle;

- (BOOL)isLoseDes;

- (BOOL)isLoseVideo;

- (BOOL)isLoseMainImage;

@end


NS_ASSUME_NONNULL_END
