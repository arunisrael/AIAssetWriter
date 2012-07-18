//
//  AIAssetWriterDelegate.h
//  AIAssetWriter
//
//  Created by Arun Israel on 7/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ALAsset;

@protocol AIAssetWriterDelegate <NSObject>

- (void) didWriteFile:(NSString *) file atPath:(NSString *) path forAsset:(ALAsset *) asset atURL:(NSURL *) assetURL;

- (void) didFailToWriteFile:(NSString *) file atPath:(NSString *) path forAsset:(ALAsset *) asset atURL:(NSURL *) assetURL;

@end
