//
//  AIAssetWriter.m
//
//  Created by Arun Israel on 6/18/12.
//  Copyright (c) 2012 Arun Israel. All rights reserved.
//

#import "AIAssetWriter.h"
#import <AssetsLibrary/AssetsLibrary.h>

@implementation AIAssetWriter

+ (void) writeAsset:(ALAsset *) asset atURL:(NSURL *) assetURL toFile:(NSString *) file atPath:(NSString *) path withDelegate:(id <AIAssetWriterDelegate>) delegate
{
    ALAssetsLibrary *library = [[ALAssetsLibrary alloc] init]; 
    [library assetForURL:assetURL
             resultBlock:^(ALAsset *asset)
            {
                ALAssetRepresentation *rep = [asset defaultRepresentation];

                Byte *buffer = (Byte*)malloc(rep.size);
                NSUInteger buffered = [rep getBytes:buffer fromOffset:0.0 length:rep.size error:nil];
                NSData *data = [NSData dataWithBytesNoCopy:buffer length:buffered freeWhenDone:YES];

                NSError *error;

                NSString *destFileFullPath = [path stringByAppendingPathComponent:file];

                [data writeToFile:destFileFullPath options:NSDataWritingAtomic error:&error];
                                
                if ([delegate respondsToSelector:@selector(didWriteFile:atPath:forAsset:atURL:)]) {
                    [delegate didWriteFile:file atPath:path forAsset:asset atURL:assetURL];
                }
             } 
            failureBlock:^(NSError *error)
            {
                if ([delegate respondsToSelector:@selector(didFailToWriteFile:atPath:forAsset:atURL:)]) {
                    [delegate didFailToWriteFile:file atPath:path forAsset:asset atURL:assetURL];
                }
            }
     ];
}
@end
