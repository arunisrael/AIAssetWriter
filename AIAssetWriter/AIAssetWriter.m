//
//  AIAssetWriter.m
//
//  Created by Arun Israel on 6/18/12.
//  Copyright (c) 2012 Arun Israel. All rights reserved.
//

#import "AIAssetWriter.h"
#import <AssetsLibrary/AssetsLibrary.h>

@implementation AIAssetWriter
@synthesize assetURL = _assetURL;
@synthesize destDir = _destDir;
@synthesize delegate = _delegate;

#pragma mark - Initializers

- (id) init
{
    return [self initWithDestDir:NSTemporaryDirectory()];
}

- (id) initWithDestDir:(NSString *) dir
{
    self = [super init];
    if (self) {
        [self setDestDir:NSTemporaryDirectory()];
    }
    return self;    
}

#pragma mark - Asset File Naming
//- (NSString *) buildAssetFileName:(ALAsset *) asset
//{
//    NSDate *assetDate = [asset valueForProperty:ALAssetPropertyDate];
//    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
//    [dateFormat setDateFormat:@"yyyy-MM-dd HH.mm.ss"];
//    return [NSString stringWithFormat:@"%@.jpg",[dateFormat stringFromDate:assetDate]];
//}

#pragma mark - Writing to Dest Dir
- (void) writeAssetToDestDirWithNamingBlock:(AssetFileNamingBlock)assetFileNamingBlock
{
    ALAssetsLibrary *library = [[ALAssetsLibrary alloc] init]; 
    __block NSString *destFileName;
    [library assetForURL:[self assetURL] 
             resultBlock:^(ALAsset *asset)
            {
                ALAssetRepresentation *rep = [asset defaultRepresentation];
                Byte *buffer = (Byte*)malloc(rep.size);
                NSUInteger buffered = [rep getBytes:buffer fromOffset:0.0 length:rep.size error:nil];
                NSData *data = [NSData dataWithBytesNoCopy:buffer length:buffered freeWhenDone:YES];
                destFileName = assetFileNamingBlock([self assetURL]);
                NSError *error;
                NSString *destFileFullPath = [[self destDir] stringByAppendingPathComponent:destFileName];
                [data writeToFile:destFileFullPath options:NSDataWritingAtomic error:&error];
                if ([[self delegate] respondsToSelector:@selector(didWriteFile:atPath:)]) {
                    [[self delegate] didWriteFile:destFileName atPath:[self destDir]];
                }
             } 
            failureBlock:^(NSError *error)
            {
                if ([[self delegate] respondsToSelector:@selector(didFailToWriteFile:atPath:withError:)]) {
                    [[self delegate] didFailToWriteFile:destFileName atPath:[self destDir] withError:error];
                }
            }
     ];
}
@end
