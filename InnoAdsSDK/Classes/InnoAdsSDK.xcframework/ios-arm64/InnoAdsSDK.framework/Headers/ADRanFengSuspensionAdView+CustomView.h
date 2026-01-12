//
//  ADRanFengSuspensionAdView+CustomView.h
//  InnoAdsSDK
//
//  Created by apple on 2025/12/19.
//

#import <InnoAdsSDK/ADRanFengSuspensionAdView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengSuspensionAdView ()


/**
 广告logo，生效样式：所有。宽高比=23:9
 */
@property (nonatomic ,strong) UIImageView *logoImageView;

/**
 关闭按钮点击区域大小，生效样式：所有
 */
@property (nonatomic, assign) CGRect closeBtnFrame;

/**
 关闭按钮图片大小，生效样式：所有
 */
@property (nonatomic, assign) UIEdgeInsets closeBtnEdgeInsets;

/**
 关闭按钮图片，生效样式：所有
 */
@property (nonatomic, strong) UIImage *closeBtnImage;

/**
 广告图片，生效样式：非标广告
 */
@property (nonatomic ,strong) UIImageView *mainImageView;

/**
 头像图片，生效样式：头像广告
 */
@property (nonatomic ,strong) UIImageView *profileImageView;

/**
 圆框区域背景，生效样式：头像广告、单行文字链、多行文字链
 */
@property (nonatomic ,strong) UIView *bgView;

/**
 文字区域背景，生效样式：头像广告、单行文字链、多行文字链
 */
@property (nonatomic ,strong) UIView *textBGView;

/**
 文字标签，生效样式：头像广告、单行文字链、多行文字链。isAutoPlay为NO时，方可自定义
 */
@property (nonatomic ,strong) UILabel *textLabel;

/**
 文字富文本样式，生效样式：多行文字链
 */
@property (nonatomic ,strong) NSMutableParagraphStyle *textParagraphStyle;

@end

NS_ASSUME_NONNULL_END
