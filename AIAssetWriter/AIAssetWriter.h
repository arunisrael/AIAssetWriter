//
//  AIAssetWriter.h
//
//  Created by Arun Israel on 6/18/12.
//  Copyright (c) 2012 Arun Israel. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MLAssetWriterDelegate <NSObject>
- (void) didWriteFile:(NSString *) fileName atPath:(NSString *) pathName;
- (void) didFailToWriteFile:(NSString *) fileName atPath:(NSString *) pathName withError:(NSError *) error;
@end


@interface AIAssetWriter : NSObject
{
    NSURL *assetURL;
    NSString *destDir;
    __weak id <MLAssetWriterDelegate> delegate;
}
@property (nonatomic, strong) NSURL *assetURL;
@property (nonatomic, strong) NSString *destDir;
@property (nonatomic, weak) id <MLAssetWriterDelegate> delegate;

typedef NSString* (^AssetFileNamingBlock)(NSURL *);

- (void) writeAssetToDestDirWithNamingBlock:(AssetFileNamingBlock)assetFileNamingBlock;
- (id) initWithDestDir:(NSString *) dir;

@end



// handle case where asset is movie
// methods for asset representation types- pick smart default (defaultRepresentation)
    //– defaultRepresentation
    //– representationForUTI:
    //– thumbnail
    //– aspectRatioThumbnail
// test + example project
// add README with examples
// default asset file naming block (new public method- writeAssetToDestDir)