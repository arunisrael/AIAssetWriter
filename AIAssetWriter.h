//
//  AIAssetWriter.h
//
//  Created by Arun Israel on 6/18/12.
//  Copyright (c) 2012 Arun Israel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AIAssetWriter : NSObject
{
    NSURL *assetURL;
    NSString *destDir;
    __weak id <MLAssetWriterDelegate> delegate;
}
@property (nonatomic, strong) NSURL *assetURL;
@property (nonatomic, strong) NSString *tempDir;
@property (nonatomic, weak) id <MLAssetWriterDelegate> delegate;

- (void) writeAssetToDestDir;
- (id) initWithDestDir:(NSString *) dir;

@end

@protocol MLAssetWriterDelegate
- (void) didWriteFile:(NSString *) fileName atPath:(NSString *) pathName;
@end


// Accept block that takes asset and returns string indicating file name
// invoke block in writeAssetToDestDir to determine file name
// default block for above renames asset to yyyy-MM-dd HH.mm.ss.EXT where ext = jpg/mov
// handle case where asset is movie
// protocol method to indicate failed to write file and error
// methods for asset representation types (default, etc?)
// test + example project
// add README with examples
