//
//  ATTracker.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 19/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAd.h"
#import "ATTrackerInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ATRefreshType){
    ATRefreshTypeNone                               = 0,
    ATRefreshTypeAutoRefresh                        = 1,
    ATRefreshTypePlayAgain                          = 2,
    ATRefreshTypeInitiation                         = 3,
    ATRefreshTypeLoadFailed                         = 4,
    ATRefreshTypeNotReady                           = 5,
    ATRefreshTypeShowStart                          = 6,
    ATRefreshTypeShowFailed                         = 7,
    ATRefreshTypeLoadFailedRetry                    = 8,
    ATRefreshTypeSerialMultiCachMode                = 9,
    ATRefreshTypeSharedPlacementPreload             = 10,
    ATRefreshTypeSharedPlacementTimer               = 11,
    ATRefreshTypeSharedPlacementSameFormatLoad      = 12,
    ATRefreshTypeSharedPlacementPresetCool          = 13,
    ATRefreshTypeSharedPlacementPresetNormal        = 14,
};

extern NSString *const kATTrackerExtraSortPriorityLevelKey;
extern NSString *const kATTrackerExtraAdmobIlrdKey;
extern NSString *const kATTrackerExtraAdmobBidPriceTypeKey;

extern NSString *const kATTrackerExtraErrorKey;
extern NSString *const kATTrackerExtraAgainLookFlagKey;
extern NSString *const kATTrackerExtraLoadSuccessRetryFlagKey;
extern NSString *const kATTrackerExtraAutoloadFlagKey;
extern NSString *const kATTrackerExtraSDKCalledFlagKey;
extern NSString *const kATTrackerExtraSDKNotCalledReasonKey;
extern NSString *const kATTrackerExtraLoadFailureReasonKey;
extern NSString *const kATTrackerExtraASIDKey;
extern NSString *const kATTrackerExtraStatusKey;
extern NSString *const kATTrackerExtraShownNetworkPriorityInfoKey;
extern NSString *const kATTrackerExtraHeaderBiddingInfoKey;
extern NSString *const kATTrackerExtraResourceTypeKey;
extern NSString *const kATTrackerExtraUnitIDKey;//Ad source id
extern NSString *const kATTrackerExtraNetworkFirmIDKey;
extern NSString *const kATTrackerExtraRefreshFlagKey;//for banner&native banner refresh
extern NSString *const kATTrackerExtraDefaultLoadFlagKey;
extern NSString *const kATTrackerExtraFilledWithinNetworkTimeoutFlagKey;
extern NSString *const kATTrackerExtraFillRequestFlagKey;
extern NSString *const kATTrackerExtraFillTimeKey;
extern NSString *const kATTrackerExtraDataFillTimeKey;
extern NSString *const kATTrackerExtraASResultKey;
extern NSString *const kATTrackerExtraAppIDKey;
extern NSString *const kATTrackerExtraLastestRequestIDKey;
extern NSString *const kATTrackerExtraLastestRequestIDMatchFlagKey;
extern NSString *const kATTrackerExtraAdFilledByReadyFlagKey;
extern NSString *const kATTrackerExtraAutoloadOnCloseFlagKey;
extern NSString *const kATTrackerExtraLoadTimeKey;
extern NSString *const kATTrackerExtraClickAddressKey;
extern NSString *const kATTrackerExtraMyOfferDefaultFalgKey;
extern NSString *const kATTrackerExtraOfferLoadedByAdSourceStatusFlagKey;
extern NSString *const kATTrackerExtraCustomObjectKey;
extern NSString *const kATTrackerExtraAdObjectKey;
extern NSString *const kATTrackerExtraAdRenderWHKey;
extern NSString *const kATTrackerExtraAdShowIntervalKey;
extern NSString *const kATTrackerExtraAppShowIntervalKey;
extern NSString *const kATTrackerExtraAdClickIntervalKey;
extern NSString *const kATTrackerExtraAdShowSceneKey;
extern NSString *const kATTrackerExtraAdShowCustomExtKey;
extern NSString *const kATTrackerExtraAdShowSDKTimeKey;
extern NSString *const kATTrackerExtraTrafficGroupIDKey;
extern NSString *const kATTrackerExtraUGUnitIDKey;
extern NSString *const kATTrackerExtraASIDKey;
extern NSString *const kATTrackerExtraFormatKey;
extern NSString *const kATTrackerExtraRequestExpectedOfferNumberFlagKey;
extern NSString *const kATTrackerExtraClickImpKey;
extern NSString *const kATTrackerExtraPlacementModelKey;
extern NSString *const kATTrackerExtraAdCacheStatusKey;
extern NSString *const kATTrackerExtraAdRequestUsedTimeKey;
extern NSString *const kATTrackerExtraAdClickTypeKey;
extern NSString *const kATTrackerExtraAdClickAreaTypeKey;
extern NSString *const kATTrackerExtraRewardedVideoRenderVideoType;

extern NSString *const kATTrackerExtralReqParTypeKey;

extern NSString *const kATTrackerExtralReqParNumKey;
extern NSString *const kATTrackerExtraAdTypeKey;


// ofm
extern NSString *const kATTrackerExtraOFMTrafficIDKey;
extern NSString *const kATTrackerExtraOFMSystemKey;
extern NSString *const kATTrackerExtraOFMPreECPMKey;
extern NSString *const kATTrackerExtraOFMKey;

extern NSString *const kATTrackerExtraAdListTypeKey;

// banner
extern NSString *const kATTrackerExtraBnnerHeightKey;
extern NSString *const kATTrackerExtraBnnerWidthKey;
extern NSString *const kATTrackerExtraBnnerTemplateIdKey;
extern NSString *const kATTrackerExtraBnnerClickAreaKey;

extern NSString *const kATTrackerExtraInterstitialStyleEnvelope;
extern NSString *const kATTrackerExtraAdAssetsResourceMaterialTypeKey;
extern NSString *const kATTrackerExtraAdxOfferInstallTypeKey;


// 比价工具TK上报
// string  unit_id     当前TopOn SDK缓存价格最高的广告源id
// string  bidprice    当前TopOn SDK缓存价格最高的广告源对应的价格
// string 竞胜：第二名(竞败方)的ilrd原始数据，   竞败：竞胜方的ilrd原始数据
extern NSString *const kATTrackerExtraMmbIlrdKey;
// 竞胜
extern NSString *const kATTrackerExtraMmbSecPriceKey;  // double 第二名(竞败方)的价格，单位美元
extern NSString *const kATTrackerExtraMmbSecBidderKey; // string 第二名(竞败方)的名字，max或is上获取到什么就传什么，如max、topon、topon adx、ironsource等
// 竞败
extern NSString *const kATTrackerExtraMmbFirstPriceKey;  // double 竞胜方（第一名）的价格
extern NSString *const kATTrackerExtraMmbFirstBidderKey; // string 竞胜方（第一名）的名字，max或is上获取到什么就传什么，如max、topon、topon adx、ironsource等
extern NSString *const kATTrackerExtraMmbLossReasonKey;  // int 竞败原因 1. 价格过低 2. 超时 3. 其他（待sdk补充）
// string 下一次 bid 上传
extern NSString *const kATTrackerExtraMmbWaterfallInfoKey;



typedef NS_ENUM(NSInteger, ATNativeADTrackType) {
    ATNativeADTrackTypeADRequest = 1, // 广告源请求
    ATNativeADTrackTypeADRecalledSuccessfully = 2, // 广告源填充
    ATNativeADTrackTypeADRecallFailed = 3,
    ATNativeADTrackTypeADShow = 4, // 广告展示
    ATNativeADTrackTypeADRefreshShow = 5,
    ATNativeADTrackTypeADClicked = 6, // 广告点击
    ATNativeADTrackTypeVideoPlayed = 7,
    ATNativeAdTrackTypeVideoStart = 8,
    ATNativeAdTrackTypeVideoEnd = 9,
    ATNativeAdTrackTypeLoad = 10,
    ATNativeAdTrackTypeBidSort = 11, // bid结果上报
    ATNativeAdTrackTypeLoadResult = 12,//currently sent when loading succeeds
    ATNativeAdTrackTypeShowAPICall = 13, // 广告show API
    ATNativeADTrackTypeEntryScenario = 16,// 上报场景
    ATNativeADTrackTypeEntryLaunch = 21,
    ATNativeADTrackTypeWin = 22,     // 比价SDK竞胜
    ATNativeADTrackTypeLoss = 23,    // 比价SDK竞败
};

typedef NS_ENUM(NSInteger, ATNativeADSourceType) {
    ATNativeADSourceTypeUnknown = 0,
    ATNativeADSourceTypeVideo = 1,
    ATNativeADSourceTypeImage = 2
};


@interface ATTracker : NSObject

+ (instancetype)sharedTracker;
- (void)trackWithPlacementID:(NSString*)placementID requestID:(NSString*)requestID trackType:(ATNativeADTrackType)trackType extra:(nullable NSDictionary*)extra;
- (void)trackClickWithAd:(nonnull id<ATAd>)ad extra:(nullable NSDictionary*)extra;
- (void)sendLaunchTrack;
/*
 * For header bidding
 */
+ (nullable NSDictionary*)headerBiddingTrackingExtraWithAd:(id<ATAd>)ad requestID:(NSString*)requestID;

+ (NSDictionary *)replaceBidPrice:(NSDictionary *)originalTKDic replacePrice:(NSString *)replacePrice unitGroup:(ATUnitGroupModel *)unitGroup;
+ (NSDictionary *)replaceBidPrice:(NSDictionary *)originalTKDic unitGroup:(ATUnitGroupModel *)unitGroup;

// 比价竞胜竞败接口
- (void)trackWinWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary*)extra;
- (void)trackLossWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary*)extra;

@end

NS_ASSUME_NONNULL_END
