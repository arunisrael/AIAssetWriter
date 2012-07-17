//
//  AIAssetWriterDelegate.h
//  AIAssetWriter
//
//  Created by Arun Israel on 7/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AIAssetWriterDelegate <NSObject>
- (void) didWriteFile:(NSString *) fileName atPath:(NSString *) pathName;
- (void) didFailToWriteFile:(NSString *) fileName atPath:(NSString *) pathName withError:(NSError *) error;
@end
