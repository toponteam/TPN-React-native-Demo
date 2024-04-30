//
//  ATBidInfoCacheManager.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 2020/4/28.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATBidInfo.h"

NS_ASSUME_NONNULL_BEGIN

#define ATHeaderBiddingListKey @"headerBiddingList"
#define ATHbParmeterErrorsKey @"hbParmeterErrors"
#define ATCurrentUnitGroupsKey @"currentUnitGroups"

@class ATUnitGroupModel;
@class ATPlacementModel;
@class ATBidWaterFallModel;
@class ATBidNotifSendModel;
@class ATWaterfall;
//@class ATWinLossSendTool;

typedef NS_ENUM(NSUInteger, ATLossType) {
    ATLossAdExpiteType = 1,
    ATLossAdCheckCacheType,
    ATLossAdWaterFallFinshType,
    ATLossAdBidFloorFilterType,
    ATLossAdC2SHBTimeOutType,
};
typedef void(^StartBidBlock)(NSDictionary * headerBiddingListDic);

@interface ATBidInfoCacheManager : NSObject

+ (instancetype)sharedManager;

- (void)saveBidInfo:(ATBidInfo*)bidInfo;
- (void)invalidateBidInfoForPlacementID:(NSString*)placementID unitGroupModel:(ATUnitGroupModel*)unitGroupModel;
- (ATBidInfo*)getBidInfoCachedForPlacementID:(NSString*)placementID unitGroup:(ATUnitGroupModel*)unitGroup;

- (NSArray<ATUnitGroupModel*>*)unitGroupWithHistoryBidInfoAvailableForPlacementID:(NSString*)placementID unitGroups:(NSArray<ATUnitGroupModel*>*)unitGroupsToInspect inhouseUnitGroups:(NSArray<ATUnitGroupModel*>*)inhouseUnitGroupsToInspect s2sUnitGroups:(NSArray<ATUnitGroupModel*>*)s2sUnitGroupsToInspect bksUnitGroups:(NSArray<ATUnitGroupModel*>*)bksUnitGroupsToInspect  directUnitGroups:(NSArray<ATUnitGroupModel*>*)directUnitGroups requestID:(NSString*)requestID;

/**
 Used for send hb loss notification
 */
- (BOOL)saveWithBidNotifSendModel:(ATBidNotifSendModel*)bidNotifSendModel forRequestID:(NSString*)requestID;
- (ATBidNotifSendModel*)getBidNotifSendModelForRequestID:(NSString*)requestID;

- (void)saveNoPriceCacheWitBidWaterFallModel:(ATBidWaterFallModel*)bidWaterfallModel;
- (void)removeNoPriceCacheWithTpBidId:(NSString*)tpBidId unitId:(NSString*)unitId;
- (ATBidWaterFallModel *)getBidWaterFallModelWithTpBidId:(NSString*)tpBidId unitId:(NSString*)unitId;


+ (NSString *)getPriceToSendHBNotifiForUnitGroup:(ATUnitGroupModel*)unitGroupModel;
+ (NSString *)getSortPriorityPriceToSendHBNotifiForUnitGroup:(ATUnitGroupModel*)unitGroupModel;
+ (NSString *)priceForBidInfo:(ATBidInfo*)bidInfo;

- (void)removeBidInfoWithDiskForPlacementID:(NSString*)placementID bidInfos:(NSArray<ATBidInfo*>*)bidInfos;


#pragma mark - bid List
- (void)saveBidRequestHBList:(NSDictionary *)hbListExtra forKeyStr:(NSString *)keyStr;
- (NSDictionary *)getBidRequestHbListForKeyStr:(NSString *)keyStr;

@end

NS_ASSUME_NONNULL_END
