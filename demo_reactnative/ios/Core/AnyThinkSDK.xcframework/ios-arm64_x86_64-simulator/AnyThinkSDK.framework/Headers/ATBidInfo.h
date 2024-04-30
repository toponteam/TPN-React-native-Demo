//
//  ATBidInfo.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 2020/4/27.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATModel.h"

@class ATUnitGroupModel;

NS_ASSUME_NONNULL_BEGIN

#define kATBiddingInitiatingFailedCode -2
#define kATBiddingNetworkTimeoutCode -3
#define KATBiddingS2SConnectionErrorCode -4
#define kATBiddingBiddingFailedByCapCode -5
#define kATBiddingBiddingFailedByPacingCode -6
#define kATBiddingBiddingFailedIntervalCode -7
#define kATBiddingBiddingFailedByExcludedCode -8
#define kATBiddingBiddingFailedIntegrationErrorCode -9
#define kATBiddingBiddingFailedBidFloor -11
#define kATBiddingBiddingFailedHighPrices -12


typedef NS_ENUM(NSInteger, ATHBAdvanceRequestType) {
    ATHBAdvanceRequestUnknownType = 0,
    ATHBAdvanceRequestYesType,
    ATHBAdvanceRequestNOType,
};


@interface ATBidInfo : ATModel

@property(nonatomic, copy) NSDictionary *bidResult;

@property(nonatomic, readonly) NSDate *expireDate;
@property(nonatomic, readonly) NSDictionary *offerDataDict;
@property(nonatomic, readonly) NSString *bidId;
@property(nonatomic, readonly) NSString *tpBidId;

@property(nonatomic, strong) NSString *ksOriginPrice;

@property(nonatomic, strong) NSString *networkOriginPrice;

@property (nonatomic, strong) NSString *sortPriorityLevel;

@property(nonatomic, strong) NSString *price;
@property(nonatomic, strong) NSString *ecpmApi;
@property(nonatomic, strong) NSString *precision;
///用来发送win/loss,转换三方平台所需要币种汇率
@property(nonatomic, strong) NSString *curRate;
@property(nonatomic, readonly) ATBiddingCurrencyType currencyType;
@property(nonatomic, readonly) id customObject;
@property(nonatomic, readonly) NSString *placementID;
@property(atomic, readonly) NSString *unitID;
@property(nonatomic, assign) NSInteger networkFirmID;
@property(nonatomic, readonly) NSString *adapterClassString;
@property(nonatomic, readonly) NSString *lURL;
@property(nonatomic, readonly) NSString *nURL;
@property(nonatomic, readonly) NSString *bURL;
@property(nonatomic, readonly) NSString *bURLWin;
@property(nonatomic, readonly) NSString *reqURL;
@property(nonatomic, readonly) BOOL bidResultCanRequest;

@property(nonatomic, readwrite) NSTimeInterval bidTime;
@property(nonatomic, readwrite) BOOL bidPriceSmallerlast;
@property(nonatomic, readwrite) BOOL bidResultIsFailed;
@property(nonatomic, strong) NSError *error;
@property(nonatomic, readonly, getter=isValid) BOOL valid;
@property(nonatomic, readonly, getter=isExpired) BOOL expired;
@property(nonatomic, readonly, getter=isSendNotif) BOOL sendNotif;
@property(nonatomic, readonly, getter=isNoPrice) BOOL noPrice;
// for load success retry send tk&da auto_req
@property(nonatomic, readwrite) BOOL isLoadSuccessRetry;
@property(nonatomic, readonly) ATUnitGroupType unitGroupType;

@property(nonatomic, assign) ATHBAdvanceRequestType HBAdvanceRequestType;

@property(nonatomic, assign) BOOL isC2SNotNeedLoad;
@property(nonatomic, strong) id c2sCustomObject;
@property(nonatomic, strong) id c2SCustomEvent;

// for send win notification
@property(nonatomic, strong) NSString *nextUGPrice;
@property(nonatomic, strong) NSString *nextUGPriceNetworkName;
@property (nonatomic, strong) NSString *nextUGID;

// only for Adx DirectOffer
@property(nonatomic, strong) NSString *offerID;
@property(nonatomic, strong) NSString *offerDspID;

@property (nonatomic, assign) BOOL isAdxNetworkDeveloperSend;
/// bid 完成时间戳
//@property (nonatomic, strong) NSDate *bidFinishDate;
/// adx 折扣策略
@property (nonatomic, assign) CGFloat adxRate;

/// C2S
/// - Parameters:
///   - placementID: placementID
///   - unitGroupUnitID: unitGroupUnitID
///   - adapterClassString: adapterClassString
///   - price:used to estimate prices and callback prices,The currency is in US dollars or Chinese yuan
///   - sortPrice: the sort price used in waterfall request,The currency is in US dollars or Chinese yuan
///   - currencyType: currency type
///   - expirationInterval: expiration Interval
///   - customObject: customObject, as ad source object
+ (instancetype)bidInfoC2SWithPlacementID:(NSString*)placementID unitGroupUnitID:(NSString*)unitGroupUnitID adapterClassString:(NSString *)adapterClassString price:(NSString*)price sortPrice:(NSString *)sortPrice currencyType:(ATBiddingCurrencyType)currencyType expirationInterval:(NSTimeInterval)expirationInterval customObject:(_Nullable id)customObject;

/// C2S
/// - Parameters:
///   - placementID: placementID
///   - unitGroupUnitID: unitGroupUnitID
///   - adapterClassString: adapterClassString
///   - price:used to estimate prices and callback prices,The currency is in US dollars or Chinese yuan
///   - currencyType: currency type
///   - expirationInterval: expiration Interval
///   - customObject: customObject, as ad source object
+ (instancetype)bidInfoC2SWithPlacementID:(NSString*)placementID
                          unitGroupUnitID:(NSString*)unitGroupUnitID
                       adapterClassString:(NSString*)adapterClassString
                                    price:(NSString*)price
                             currencyType:(ATBiddingCurrencyType)currencyType
                       expirationInterval:(NSTimeInterval)expirationInterval
                             customObject:(_Nullable id)customObject;

/// S2S
- (instancetype)initS2SWithDictionary:(NSDictionary*)dictionary
                       placementID:(NSString*)placementID
                    unitGroupModel:(ATUnitGroupModel*)unitGroupModel
                      currencyType:(ATBiddingCurrencyType)currencyType;

/// adx cache 
- (instancetype)initWithCacheDictionary:(NSDictionary*)dictionary;
- (NSDictionary *)serializationToDictionary;

- (void)hasBeenSendNotif;
- (void)saveOfferModelDspID:(NSString *)offerDspID withOfferID:(NSString *)offerID;
- (void)releasCustomObject;
- (NSString *)getBidInfoPrice;
- (NSString *)getBidInfoSortPriorityLevel;
+ (NSString *)getExchRateC2U:(NSString *)placementID;

@end

NS_ASSUME_NONNULL_END
