//
//  ADRanFengServerVerificationOptions.h
//  ADRanFengSDK
//
//  Created by apple on 2025/4/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengServerVerificationOptions : NSObject

//服务器端验证回调中包含的可选自定义奖励字符串
@property(nonatomic, copy, nullable) NSString *extra;

@end

NS_ASSUME_NONNULL_END
