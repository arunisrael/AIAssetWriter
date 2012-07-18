//
//  AIAssetWriter.h
//
//  Created by Arun Israel on 6/18/12.
//  Copyright (c) 2012 Arun Israel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AIAssetWriterDelegate.h"

@class ALAsset;

@interface AIAssetWriter : NSObject

+ (void) writeAsset:(ALAsset *) asset atURL:(NSURL *) assetURL toFile:(NSString *) file atPath:(NSString *) path withDelegate:(id <AIAssetWriterDelegate>) delegate;

@end

// handle case where asset is movie
// methods for asset representation types- pick smart default (defaultRepresentation)
    //– defaultRepresentation
    //– representationForUTI:
    //– thumbnail
    //– aspectRatioThumbnail
// test + example project
// add README with examples