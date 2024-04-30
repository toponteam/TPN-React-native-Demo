//
//  ATAdManagement.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 04/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef ATAdManagement_h
#define ATAdManagement_h
@protocol ATAd;
@class ATPlacementModel;
@class ATUnitGroupModel;
@class ATWaterfall;
extern NSString *const kATAdAssetsCustomEventKey;
extern NSString *const kATAdAssetsCustomObjectKey;
extern NSString *const kATAdAssetsUnitIDKey;

typedef NS_ENUM(NSInteger, ATAdSourceStatus) {
    ATAdSourceStatusInvalid = 0,//pacing & cap_by_hour/cap_by_day
    ATAdSourceStatusNoOffer = 1,
    ATAdSourceStatusOfferNotReady = 2,
    ATAdSourceStatusOfferExpired = 3,
    ATAdSourceStatusReady = 4
};

/// 默认优先级为-1，代表不在waterfall中的异常值
static const NSInteger kATUnusualPriority = -1;

@protocol ATAdManagement<NSObject>
-(void) addAdWithADAssets:(NSDictionary*)assets withPlacementSetting:(ATPlacementModel*)placementModel unitGroup:(ATUnitGroupModel*)unitGroup finalWaterfall:(ATWaterfall*)finalWaterfall requestID:(NSString*)requestID;
-(BOOL) inspectAdSourceStatusWithPlacementModel:(ATPlacementModel*)placementModel unitGroup:(ATUnitGroupModel*)unitGroup finalWaterfall:(ATWaterfall*)finalWaterfall requestID:(NSString*)requestID extraInfo:(NSArray<NSDictionary*>*__autoreleasing*)extraInfo;
-(void) updateAdSourceOffersWithPlacementModel:(ATPlacementModel*)placementModel requestID:(NSString*)requestID;
//-(void) invalidateStatusForAd:(id<ATAd>)ad;
-(BOOL) adSourceStatusInPlacementModel:(ATPlacementModel*)placementModel unitGroup:(ATUnitGroupModel*)unitGroup;
- (id<ATAd>)getAdStorageHigestPriceWithPlacementID:(NSString *)placementID;
- (id<ATAd>)getAdStorageHigestPriceWithPosition:(NSInteger)position placementID:(NSString *)placementID;

/**
 
 */
-(NSArray<id<ATAd>>*) adsWithPlacementID:(NSString*)placementID;

-(id<ATAd>) adWithPlacementModel:(ATPlacementModel*)placementModel unitGroup:(ATUnitGroupModel*)unitGroup;

-(NSArray<id<ATAd>>*) availableStatusAdsWithPlacementModel:(ATPlacementModel*)placementModel;

/**
 * Clear all cached offer
 */
-(void) clearCache;

/*
 *Return the following structure, indicating the status of the ad-sources within the placement:
 {
     @0:@(ATAdSourceStatusInvalid),
     @1:@(ATAdSourceStatusOfferNotReady),
     @2:@(ATAdSourceStatusOfferExpired),
     @3:@(ATAdSourceStatusReady)
 }
 */
-(void) removeAdForPlacementID:(NSString*)placementID unitID:(NSString*)unitID;
-(void) removeCahceForPlacementID:(NSString*)placementID unitGroupModel:(ATUnitGroupModel*)unitGroupModel;
- (NSArray<id<ATAd>> *)validCachedAdsForPlacementID:(NSString*)placementID;

@end

#endif /* ATAdManagement_h */
