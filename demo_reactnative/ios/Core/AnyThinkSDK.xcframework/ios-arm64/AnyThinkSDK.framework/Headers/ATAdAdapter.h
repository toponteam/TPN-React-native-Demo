//
//  ATAdAdapter.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 05/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef ATAdAdapter_h
#define ATAdAdapter_h

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATADapterCustomInfoStatisticsInfoKey;
extern NSString *const kATAdapterCustomInfoPlacementModelKey;
extern NSString *const kATAdapterCustomInfoUnitGroupModelKey;
extern NSString *const kATAdapterCustomInfoRequestIDKey;
extern NSString *const kATAdapterCustomInfoExtraKey;
extern NSString *const kATAdapterCustomInfoBuyeruIdKey;
extern NSString *const kATAdapterCustomInfoBidInfoKey;
extern NSString *const kATAdapterCustomInfoBidResultKey;
extern NSString *const kATAdapterCustomInfoBidPlacementIDKey;
extern NSString *const kATAdapterCustomInfoMaxFilledPriceKey;
extern NSString *const kATAdapterAdmobEstimatePriceNumKey;
extern NSString *const kATAdapterAdmobEstimatePriceSwitchKey;
extern NSString *const kATAdapterCustomInfoBaiduInfoKey;
extern NSString *const kATAdapterCustomInfoAdmobRequestAgentInfoKey;
extern NSString *const kATAdapterCustomInfoKuaishouInfoKey;


extern NSString *const kATHeaderBiddingParametersUnitIdKey;
extern NSString *const kATHeaderBiddingParametersNetworkFirmIdKey;
extern NSString *const kATHeaderBiddingParametersAdFormatKey;
extern NSString *const kATHeaderBiddingParametersAdSourceIdKey;
extern NSString *const kATHeaderBiddingParametersEcpofferKey;
extern NSString *const kATHeaderBiddingParametersGetOfferKey;
extern NSString *const kATHeaderBiddingParametersUnitTypeKey;
extern NSString *const kATHeaderBiddingParametersDisplayManagerVersionKey;
extern NSString *const kATHeaderBiddingParametersTplVersionKey;
extern NSString *const kATHeaderBiddingParametersAppIdKey;
extern NSString *const kATHeaderBiddingParametersAppKey;
extern NSString *const kATHeaderBiddingParametersAccountIdKey;
extern NSString *const kATHeaderBiddingParametersBuyeruIdKey;
extern NSString *const kATHeaderBiddingParametersBidTokenKey;
extern NSString *const kATHeaderBiddingParametersAdWidthKey;
extern NSString *const kATHeaderBiddingParametersAdHeightKey;

extern NSString *const kATHeaderBiddingParametersDirectOfferKey;
extern NSString *const kATDirectOfferHeaderBiddingUnitGroupsKey;

extern NSString *const kATHeaderBiddingParametersDirectOfferSizeKey;


extern NSString *const kATHeaderBiddingParametersBidFormatKey;
extern NSString *const kATHeaderBiddingParametersBidderTypeKey;
extern NSString *const kATHeaderBiddingParametersUnitGroupKey;

extern NSString *const kATHeaderBiddingParametersSDKInfoKey;
extern NSString *const kATHeaderBiddingParametersADPAcceptTypeKey;
extern NSString *const kATHeaderBiddingParametersADXVASTMaxVersionKey;

extern NSString *const kATHeaderBiddingParametersAdmobBidTypeKey;
extern NSString *const kATHeaderBiddingParametersNetworkIdKey;


@protocol ATAd;
@class ATPlacementModel;
@class ATUnitGroupModel;
@class ATMyOfferOfferModel;
@class ATBidInfo;
@class ATWaterfall;
@class ATInHouseBidRequest;

typedef NS_ENUM(NSInteger, ATBiddingLossType) {
    ATBiddingLossWithLowPriceInNormal = 103,
    ATBiddingLossWithLowPriceInHB = 102,
    ATBiddingLossWithBiddingTimeOut = 2,
    ATBiddingLossWithExpire = 5,
    ATBiddingLossWithFloorFilter = 104
};

@protocol ATAdAdapter <NSObject>

#pragma mark - Initialize network SDK and start load ad with network SDK

/// Adapter initialization method
/// - Parameters:
///   - serverInfo: Data from the server
///   - localInfo: Data from the local
- (nonnull instancetype)initWithNetworkCustomInfo:(nonnull NSDictionary *)serverInfo
                                localInfo:(nonnull NSDictionary *)localInfo;

#pragma mark - Normal
/// Adapter sends a load request, means the ad source sends an ad load request
/// - Parameters:
///   - serverInfo: Data from the server
///   - localInfo: Data from the local
///   - completion: completion
- (void)loadADWithInfo:(nonnull NSDictionary *)serverInfo
             localInfo:(nonnull NSDictionary *)localInfo
            completion:(nonnull void (^)(NSArray<NSDictionary *> * _Nonnull array, NSError * _Nonnull error))completion;

/// Check whether the ad source is ready
/// - Parameters:
///   - customObject: ad source object
///   - info: info
+ (BOOL)adReadyWithCustomObject:(nonnull id)customObject info:(nonnull NSDictionary *)info;

@optional

@property (nonatomic,copy) void (^metaDataDidLoadedBlock)(void);

/*
 * Create a rewarded instance for download event and FOR DOWNLOAD EVENT ONLY.
 */
+ (id<ATAd>)readyFilledAdWithPlacementModel:(ATPlacementModel *)placementModel
                                  requestID:(NSString *)requestID
                                   priority:(NSInteger)priority
                                  unitGroup:(ATUnitGroupModel *)unitGroup
                             finalWaterfall:(ATWaterfall *)finalWaterfall
                                  localInfo:(NSDictionary *)localInfo;
+ (BOOL)adReadyForInfo:(NSDictionary *)info;

@end
#endif /* ATAdAdapter_h */

NS_ASSUME_NONNULL_END
