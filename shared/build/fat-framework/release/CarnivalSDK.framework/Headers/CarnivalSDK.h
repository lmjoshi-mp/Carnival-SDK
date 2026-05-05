#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class CSDKChatMessage, CSDKCruiseSDK, CSDKCruiseSDKConfig, CSDKAuthApi, CSDKChatApi, CSDKItineraryApi, CSDKOrderApi, CSDKPreferencesApi, CSDKSyncApi, CSDKKtor_client_coreHttpClient, CSDKKitchenOrder, CSDKOrderStatus, CSDKUserPreferences, CSDKSyncQueueItem, CSDKItineraryItem, CSDKUserSession, CSDKKotlinx_coroutines_coreCoroutineDispatcher, CSDKKotlinThrowable, CSDKDeviceInfo, CSDKKotlinx_serialization_jsonJson, CSDKResultState<__covariant T>, CSDKDomainError, CSDKResultStateError, CSDKKotlinNothing, CSDKResultStateLoading, CSDKResultStateSuccess<T>, CSDKSyncOperationType, CSDKRemoteSyncChangeDto, CSDKItineraryPageDto, CSDKChatMessageDto, CSDKPreferencesDto, CSDKUserSessionDto, CSDKOrderDto, CSDKChatMessageDtoCompanion, CSDKItineraryItemDtoCompanion, CSDKItineraryItemDto, CSDKItineraryPageDtoCompanion, CSDKLoginRequestDtoCompanion, CSDKLoginRequestDto, CSDKOrderDtoCompanion, CSDKPreferencesDtoCompanion, CSDKRemoteSyncChangeDtoCompanion, CSDKUserSessionDtoCompanion, CSDKCruiseRemoteDataSource, CSDKCruiseLocalDataSource, CSDKJsonCodec, CSDKCachePolicy, CSDKExponentialBackoff, CSDKDomainErrorCacheError, CSDKDomainErrorNetworkError, CSDKDomainErrorSyncError, CSDKDomainErrorUnauthorizedError, CSDKKotlinx_datetimeInstant, CSDKKotlinEnumCompanion, CSDKKotlinEnum<E>, CSDKKotlinArray<T>, CSDKKtor_client_coreHttpClientEngineConfig, CSDKKtor_client_coreHttpClientConfig<T>, CSDKKtor_eventsEvents, CSDKKtor_client_coreHttpReceivePipeline, CSDKKtor_client_coreHttpRequestPipeline, CSDKKtor_client_coreHttpResponsePipeline, CSDKKtor_client_coreHttpSendPipeline, CSDKKotlinException, CSDKKotlinRuntimeException, CSDKKotlinIllegalStateException, CSDKKotlinAbstractCoroutineContextElement, CSDKKotlinx_coroutines_coreCoroutineDispatcherKey, CSDKKotlinx_serialization_coreSerializersModule, CSDKKotlinx_serialization_jsonJsonDefault, CSDKKotlinx_serialization_jsonJsonElement, CSDKKotlinx_serialization_jsonJsonConfiguration, CSDKKotlinx_datetimeInstantCompanion, CSDKKtor_client_coreHttpRequestData, CSDKKtor_client_coreHttpResponseData, CSDKKtor_client_coreProxyConfig, CSDKKtor_utilsAttributeKey<T>, CSDKKtor_eventsEventDefinition<T>, CSDKKtor_utilsPipelinePhase, CSDKKtor_utilsPipeline<TSubject, TContext>, CSDKKtor_client_coreHttpReceivePipelinePhases, CSDKKtor_client_coreHttpResponse, CSDKKotlinUnit, CSDKKtor_client_coreHttpRequestPipelinePhases, CSDKKtor_client_coreHttpRequestBuilder, CSDKKtor_client_coreHttpResponsePipelinePhases, CSDKKtor_client_coreHttpResponseContainer, CSDKKtor_client_coreHttpClientCall, CSDKKtor_client_coreHttpSendPipelinePhases, CSDKKotlinAbstractCoroutineContextKey<B, E>, CSDKKotlinx_serialization_jsonJsonElementCompanion, CSDKKotlinx_serialization_jsonClassDiscriminatorMode, CSDKKotlinx_serialization_coreSerialKind, CSDKKtor_httpUrl, CSDKKtor_httpHttpMethod, CSDKKtor_httpOutgoingContent, CSDKKtor_httpHttpStatusCode, CSDKKtor_utilsGMTDate, CSDKKtor_httpHttpProtocolVersion, CSDKKtor_httpHeadersBuilder, CSDKKtor_client_coreHttpRequestBuilderCompanion, CSDKKtor_httpURLBuilder, CSDKKtor_utilsTypeInfo, CSDKKtor_client_coreHttpClientCallCompanion, CSDKKtor_httpUrlCompanion, CSDKKtor_httpURLProtocol, CSDKKtor_httpHttpMethodCompanion, CSDKKtor_httpContentType, CSDKKotlinCancellationException, CSDKKtor_httpHttpStatusCodeCompanion, CSDKKtor_utilsGMTDateCompanion, CSDKKtor_utilsWeekDay, CSDKKtor_utilsMonth, CSDKKtor_httpHttpProtocolVersionCompanion, CSDKKtor_ioMemory, CSDKKtor_ioChunkBuffer, CSDKKtor_ioBuffer, CSDKKotlinByteArray, CSDKKtor_ioByteReadPacket, CSDKKtor_utilsStringValuesBuilderImpl, CSDKKtor_httpURLBuilderCompanion, CSDKKtor_httpURLProtocolCompanion, CSDKKtor_httpHeaderValueParam, CSDKKtor_httpHeaderValueWithParametersCompanion, CSDKKtor_httpHeaderValueWithParameters, CSDKKtor_httpContentTypeCompanion, CSDKKtor_utilsWeekDayCompanion, CSDKKtor_utilsMonthCompanion, CSDKKtor_ioMemoryCompanion, CSDKKtor_ioBufferCompanion, CSDKKtor_ioChunkBufferCompanion, CSDKKotlinByteIterator, CSDKKtor_ioInputCompanion, CSDKKtor_ioInput, CSDKKtor_ioByteReadPacketCompanion, CSDKKotlinKTypeProjection, CSDKKotlinKVariance, CSDKKotlinKTypeProjectionCompanion;

@protocol CSDKKotlinx_coroutines_coreFlow, CSDKNetworkMonitor, CSDKLocalStore, CSDKSecureTokenStore, CSDKDispatcherProvider, CSDKTimeProvider, CSDKKotlinx_coroutines_coreCoroutineScope, CSDKKotlinx_coroutines_coreStateFlow, CSDKKotlinx_serialization_coreKSerializer, CSDKSyncRemoteGateway, CSDKAuthRepository, CSDKChatRepository, CSDKItineraryRepository, CSDKOrderRepository, CSDKPreferencesRepository, CSDKConflictResolver, CSDKSyncRepository, CSDKKotlinComparable, CSDKDeviceInfoProvider, CSDKFileSystemProvider, CSDKPlatformLogger, CSDKKotlinx_coroutines_coreFlowCollector, CSDKKotlinCoroutineContext, CSDKKtor_ioCloseable, CSDKKtor_client_coreHttpClientEngine, CSDKKtor_client_coreHttpClientEngineCapability, CSDKKtor_utilsAttributes, CSDKKotlinCoroutineContextKey, CSDKKotlinCoroutineContextElement, CSDKKotlinContinuation, CSDKKotlinContinuationInterceptor, CSDKKotlinx_coroutines_coreRunnable, CSDKKotlinx_coroutines_coreSharedFlow, CSDKKotlinx_serialization_coreDeserializationStrategy, CSDKKotlinx_serialization_coreSerializationStrategy, CSDKKotlinx_serialization_coreSerialFormat, CSDKKotlinx_serialization_coreStringFormat, CSDKKotlinx_serialization_coreEncoder, CSDKKotlinx_serialization_coreSerialDescriptor, CSDKKotlinx_serialization_coreDecoder, CSDKKotlinIterator, CSDKKtor_client_coreHttpClientPlugin, CSDKKotlinx_coroutines_coreDisposableHandle, CSDKKotlinSuspendFunction2, CSDKKotlinx_serialization_coreSerializersModuleCollector, CSDKKotlinKClass, CSDKKotlinx_serialization_jsonJsonNamingStrategy, CSDKKotlinx_serialization_coreCompositeEncoder, CSDKKotlinAnnotation, CSDKKotlinx_serialization_coreCompositeDecoder, CSDKKotlinx_datetimeDateTimeFormat, CSDKKtor_httpHeaders, CSDKKotlinx_coroutines_coreJob, CSDKKotlinFunction, CSDKKtor_httpHttpMessage, CSDKKtor_ioByteReadChannel, CSDKKtor_httpHttpMessageBuilder, CSDKKtor_client_coreHttpRequest, CSDKKotlinKDeclarationContainer, CSDKKotlinKAnnotatedElement, CSDKKotlinKClassifier, CSDKKotlinAppendable, CSDKKtor_httpParameters, CSDKKotlinMapEntry, CSDKKtor_utilsStringValues, CSDKKotlinx_coroutines_coreChildHandle, CSDKKotlinx_coroutines_coreChildJob, CSDKKotlinSequence, CSDKKotlinx_coroutines_coreSelectClause0, CSDKKtor_ioReadSession, CSDKKotlinSuspendFunction1, CSDKKtor_utilsStringValuesBuilder, CSDKKtor_httpParametersBuilder, CSDKKotlinKType, CSDKKotlinx_coroutines_coreParentJob, CSDKKotlinx_coroutines_coreSelectInstance, CSDKKotlinx_coroutines_coreSelectClause, CSDKKtor_ioObjectPool;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface CSDKBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface CSDKBase (CSDKBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface CSDKMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface CSDKMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorCSDKKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface CSDKNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface CSDKByte : CSDKNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface CSDKUByte : CSDKNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface CSDKShort : CSDKNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface CSDKUShort : CSDKNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface CSDKInt : CSDKNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface CSDKUInt : CSDKNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface CSDKLong : CSDKNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface CSDKULong : CSDKNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface CSDKFloat : CSDKNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface CSDKDouble : CSDKNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface CSDKBoolean : CSDKNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthApi")))
@interface CSDKAuthApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)cachedSession __attribute__((swift_name("cachedSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)loginEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("login(email:password:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatApi")))
@interface CSDKChatApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)receiveRoomId:(NSString *)roomId __attribute__((swift_name("receive(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)sendMessage:(CSDKChatMessage *)message __attribute__((swift_name("send(message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CruiseSDK")))
@interface CSDKCruiseSDK : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cruiseSDK __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKCruiseSDK *shared __attribute__((swift_name("shared")));
- (void)initializeConfig:(CSDKCruiseSDKConfig *)config __attribute__((swift_name("initialize(config:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@property (readonly) CSDKAuthApi *auth __attribute__((swift_name("auth")));
@property (readonly) CSDKChatApi *chat __attribute__((swift_name("chat")));
@property (readonly) CSDKItineraryApi *itinerary __attribute__((swift_name("itinerary")));
@property (readonly) CSDKOrderApi *order __attribute__((swift_name("order")));
@property (readonly) CSDKPreferencesApi *preferences __attribute__((swift_name("preferences")));
@property (readonly) CSDKSyncApi *sync __attribute__((swift_name("sync")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CruiseSDKConfig")))
@interface CSDKCruiseSDKConfig : CSDKBase
- (instancetype)initWithBaseUrl:(NSString *)baseUrl enableNetworkLogs:(BOOL)enableNetworkLogs networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor localStore:(id<CSDKLocalStore>)localStore secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider pollingIntervalMillis:(int64_t)pollingIntervalMillis timeProvider:(id<CSDKTimeProvider>)timeProvider externalScope:(id<CSDKKotlinx_coroutines_coreCoroutineScope> _Nullable)externalScope httpClient:(CSDKKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("init(baseUrl:enableNetworkLogs:networkMonitor:localStore:secureTokenStore:dispatcherProvider:pollingIntervalMillis:timeProvider:externalScope:httpClient:)"))) __attribute__((objc_designated_initializer));
- (CSDKCruiseSDKConfig *)doCopyBaseUrl:(NSString *)baseUrl enableNetworkLogs:(BOOL)enableNetworkLogs networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor localStore:(id<CSDKLocalStore>)localStore secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider pollingIntervalMillis:(int64_t)pollingIntervalMillis timeProvider:(id<CSDKTimeProvider>)timeProvider externalScope:(id<CSDKKotlinx_coroutines_coreCoroutineScope> _Nullable)externalScope httpClient:(CSDKKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("doCopy(baseUrl:enableNetworkLogs:networkMonitor:localStore:secureTokenStore:dispatcherProvider:pollingIntervalMillis:timeProvider:externalScope:httpClient:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *baseUrl __attribute__((swift_name("baseUrl")));
@property (readonly) id<CSDKDispatcherProvider> dispatcherProvider __attribute__((swift_name("dispatcherProvider")));
@property (readonly) BOOL enableNetworkLogs __attribute__((swift_name("enableNetworkLogs")));
@property (readonly) id<CSDKKotlinx_coroutines_coreCoroutineScope> _Nullable externalScope __attribute__((swift_name("externalScope")));
@property (readonly) CSDKKtor_client_coreHttpClient * _Nullable httpClient __attribute__((swift_name("httpClient")));
@property (readonly) id<CSDKLocalStore> localStore __attribute__((swift_name("localStore")));
@property (readonly) id<CSDKNetworkMonitor> networkMonitor __attribute__((swift_name("networkMonitor")));
@property (readonly) int64_t pollingIntervalMillis __attribute__((swift_name("pollingIntervalMillis")));
@property (readonly) id<CSDKSecureTokenStore> secureTokenStore __attribute__((swift_name("secureTokenStore")));
@property (readonly) id<CSDKTimeProvider> timeProvider __attribute__((swift_name("timeProvider")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryApi")))
@interface CSDKItineraryApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)getPage:(int32_t)page pageSize:(int32_t)pageSize __attribute__((swift_name("get(page:pageSize:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderApi")))
@interface CSDKOrderApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)observeUserId:(NSString *)userId __attribute__((swift_name("observe(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)placeOrder:(CSDKKitchenOrder *)order __attribute__((swift_name("place(order:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)updateStatusOrderId:(NSString *)orderId status:(CSDKOrderStatus *)status __attribute__((swift_name("updateStatus(orderId:status:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreferencesApi")))
@interface CSDKPreferencesApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)getUserId:(NSString *)userId __attribute__((swift_name("get(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)savePreferences:(CSDKUserPreferences *)preferences __attribute__((swift_name("save(preferences:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SyncApi")))
@interface CSDKSyncApi : CSDKBase
- (id<CSDKKotlinx_coroutines_coreFlow>)trigger __attribute__((swift_name("trigger()")));
@end

__attribute__((swift_name("LocalStore")))
@protocol CSDKLocalStore
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)enqueueSyncItem:(CSDKSyncQueueItem *)item completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("enqueueSync(item:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getItineraryPage:(int32_t)page pageSize:(int32_t)pageSize completionHandler:(void (^)(NSArray<CSDKItineraryItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getItinerary(page:pageSize:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessageMessageId:(NSString *)messageId completionHandler:(void (^)(CSDKChatMessage * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessage(messageId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessagesRoomId:(NSString *)roomId completionHandler:(void (^)(NSArray<CSDKChatMessage *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessages(roomId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrderOrderId:(NSString *)orderId completionHandler:(void (^)(CSDKKitchenOrder * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrder(orderId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrdersUserId:(NSString *)userId completionHandler:(void (^)(NSArray<CSDKKitchenOrder *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrders(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPreferencesUserId:(NSString *)userId completionHandler:(void (^)(CSDKUserPreferences * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getPreferences(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSessionWithCompletionHandler:(void (^)(CSDKUserSession * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getSession(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSyncQueueLimit:(int32_t)limit completionHandler:(void (^)(NSArray<CSDKSyncQueueItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSyncQueue(limit:completionHandler:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeItinerary __attribute__((swift_name("observeItinerary()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeMessagesRoomId:(NSString *)roomId __attribute__((swift_name("observeMessages(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeOrdersUserId:(NSString *)userId __attribute__((swift_name("observeOrders(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observePreferencesUserId:(NSString *)userId __attribute__((swift_name("observePreferences(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSession __attribute__((swift_name("observeSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSyncQueue __attribute__((swift_name("observeSyncQueue()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeSyncItemSyncItemId:(NSString *)syncItemId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeSyncItem(syncItemId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateSyncItemItem:(CSDKSyncQueueItem *)item completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("updateSyncItem(item:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertItineraryItems:(NSArray<CSDKItineraryItem *> *)items completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertItinerary(items:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertMessageMessage:(CSDKChatMessage *)message completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertMessage(message:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertMessagesMessages:(NSArray<CSDKChatMessage *> *)messages completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertMessages(messages:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertOrderOrder:(CSDKKitchenOrder *)order completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertOrder(order:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertPreferencesPreferences:(CSDKUserPreferences *)preferences completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertPreferences(preferences:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertSessionSession:(CSDKUserSession *)session completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertSession(session:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InMemoryLocalStore")))
@interface CSDKInMemoryLocalStore : CSDKBase <CSDKLocalStore>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)enqueueSyncItem:(CSDKSyncQueueItem *)item completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("enqueueSync(item:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getItineraryPage:(int32_t)page pageSize:(int32_t)pageSize completionHandler:(void (^)(NSArray<CSDKItineraryItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getItinerary(page:pageSize:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessageMessageId:(NSString *)messageId completionHandler:(void (^)(CSDKChatMessage * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessage(messageId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessagesRoomId:(NSString *)roomId completionHandler:(void (^)(NSArray<CSDKChatMessage *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessages(roomId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrderOrderId:(NSString *)orderId completionHandler:(void (^)(CSDKKitchenOrder * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrder(orderId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrdersUserId:(NSString *)userId completionHandler:(void (^)(NSArray<CSDKKitchenOrder *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrders(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPreferencesUserId:(NSString *)userId completionHandler:(void (^)(CSDKUserPreferences * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getPreferences(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSessionWithCompletionHandler:(void (^)(CSDKUserSession * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getSession(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSyncQueueLimit:(int32_t)limit completionHandler:(void (^)(NSArray<CSDKSyncQueueItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSyncQueue(limit:completionHandler:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeItinerary __attribute__((swift_name("observeItinerary()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeMessagesRoomId:(NSString *)roomId __attribute__((swift_name("observeMessages(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeOrdersUserId:(NSString *)userId __attribute__((swift_name("observeOrders(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observePreferencesUserId:(NSString *)userId __attribute__((swift_name("observePreferences(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSession __attribute__((swift_name("observeSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSyncQueue __attribute__((swift_name("observeSyncQueue()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeSyncItemSyncItemId:(NSString *)syncItemId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeSyncItem(syncItemId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateSyncItemItem:(CSDKSyncQueueItem *)item completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("updateSyncItem(item:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertItineraryItems:(NSArray<CSDKItineraryItem *> *)items completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertItinerary(items:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertMessageMessage:(CSDKChatMessage *)message completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertMessage(message:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertMessagesMessages:(NSArray<CSDKChatMessage *> *)messages completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertMessages(messages:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertOrderOrder:(CSDKKitchenOrder *)order completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertOrder(order:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertPreferencesPreferences:(CSDKUserPreferences *)preferences completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertPreferences(preferences:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upsertSessionSession:(CSDKUserSession *)session completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("upsertSession(session:completionHandler:)")));
@end

__attribute__((swift_name("DispatcherProvider")))
@protocol CSDKDispatcherProvider
@required
@property (readonly, getter=default) CSDKKotlinx_coroutines_coreCoroutineDispatcher *default_ __attribute__((swift_name("default_")));
@property (readonly) CSDKKotlinx_coroutines_coreCoroutineDispatcher *io __attribute__((swift_name("io")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultDispatcherProvider")))
@interface CSDKDefaultDispatcherProvider : CSDKBase <CSDKDispatcherProvider>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly, getter=default) CSDKKotlinx_coroutines_coreCoroutineDispatcher *default_ __attribute__((swift_name("default_")));
@property (readonly) CSDKKotlinx_coroutines_coreCoroutineDispatcher *io __attribute__((swift_name("io")));
@end

__attribute__((swift_name("FileSystemProvider")))
@protocol CSDKFileSystemProvider
@required
- (BOOL)deletePath:(NSString *)path __attribute__((swift_name("delete(path:)")));
- (BOOL)existsPath:(NSString *)path __attribute__((swift_name("exists(path:)")));
- (NSString * _Nullable)readTextPath:(NSString *)path __attribute__((swift_name("readText(path:)")));
- (void)writeTextPath:(NSString *)path content:(NSString *)content __attribute__((swift_name("writeText(path:content:)")));
@end

__attribute__((swift_name("PlatformLogger")))
@protocol CSDKPlatformLogger
@required
- (void)dMessage:(NSString *)message __attribute__((swift_name("d(message:)")));
- (void)eMessage:(NSString *)message throwable:(CSDKKotlinThrowable * _Nullable)throwable __attribute__((swift_name("e(message:throwable:)")));
- (void)iMessage:(NSString *)message __attribute__((swift_name("i(message:)")));
- (void)wMessage:(NSString *)message __attribute__((swift_name("w(message:)")));
@end

__attribute__((swift_name("NetworkMonitor")))
@protocol CSDKNetworkMonitor
@required
@property (readonly) id<CSDKKotlinx_coroutines_coreStateFlow> isOnline __attribute__((swift_name("isOnline")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MutableNetworkMonitor")))
@interface CSDKMutableNetworkMonitor : CSDKBase <CSDKNetworkMonitor>
- (instancetype)initWithInitialOnline:(BOOL)initialOnline __attribute__((swift_name("init(initialOnline:)"))) __attribute__((objc_designated_initializer));
- (void)updateIsOnline:(BOOL)isOnline __attribute__((swift_name("update(isOnline:)")));
@property (readonly) id<CSDKKotlinx_coroutines_coreStateFlow> isOnline __attribute__((swift_name("isOnline")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceInfo")))
@interface CSDKDeviceInfo : CSDKBase
- (instancetype)initWithPlatform:(NSString *)platform osVersion:(NSString *)osVersion deviceModel:(NSString *)deviceModel appVersion:(NSString *)appVersion __attribute__((swift_name("init(platform:osVersion:deviceModel:appVersion:)"))) __attribute__((objc_designated_initializer));
- (CSDKDeviceInfo *)doCopyPlatform:(NSString *)platform osVersion:(NSString *)osVersion deviceModel:(NSString *)deviceModel appVersion:(NSString *)appVersion __attribute__((swift_name("doCopy(platform:osVersion:deviceModel:appVersion:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *appVersion __attribute__((swift_name("appVersion")));
@property (readonly) NSString *deviceModel __attribute__((swift_name("deviceModel")));
@property (readonly) NSString *osVersion __attribute__((swift_name("osVersion")));
@property (readonly) NSString *platform __attribute__((swift_name("platform")));
@end

__attribute__((swift_name("DeviceInfoProvider")))
@protocol CSDKDeviceInfoProvider
@required
- (CSDKDeviceInfo *)getDeviceInfo __attribute__((swift_name("getDeviceInfo()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExponentialBackoff")))
@interface CSDKExponentialBackoff : CSDKBase
- (instancetype)initWithBaseDelayMillis:(int64_t)baseDelayMillis maxDelayMillis:(int64_t)maxDelayMillis __attribute__((swift_name("init(baseDelayMillis:maxDelayMillis:)"))) __attribute__((objc_designated_initializer));
- (int64_t)nextDelayMillisRetryCount:(int32_t)retryCount __attribute__((swift_name("nextDelayMillis(retryCount:)")));
@end

__attribute__((swift_name("SecureTokenStore")))
@protocol CSDKSecureTokenStore
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)clearWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("clear(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTokenWithCompletionHandler:(void (^)(NSString * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getToken(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveTokenToken:(NSString *)token completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveToken(token:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InMemorySecureTokenStore")))
@interface CSDKInMemorySecureTokenStore : CSDKBase <CSDKSecureTokenStore>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)clearWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("clear(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTokenWithCompletionHandler:(void (^)(NSString * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getToken(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveTokenToken:(NSString *)token completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveToken(token:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonCodec")))
@interface CSDKJsonCodec : CSDKBase
- (instancetype)initWithJson:(CSDKKotlinx_serialization_jsonJson *)json __attribute__((swift_name("init(json:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)decodeSerializer:(id<CSDKKotlinx_serialization_coreKSerializer>)serializer raw:(NSString *)raw __attribute__((swift_name("decode(serializer:raw:)")));
- (NSString *)encodeSerializer:(id<CSDKKotlinx_serialization_coreKSerializer>)serializer value:(id _Nullable)value __attribute__((swift_name("encode(serializer:value:)")));
@end

__attribute__((swift_name("ResultState")))
@interface CSDKResultState<__covariant T> : CSDKBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResultStateError")))
@interface CSDKResultStateError : CSDKResultState<CSDKKotlinNothing *>
- (instancetype)initWithError:(CSDKDomainError *)error __attribute__((swift_name("init(error:)"))) __attribute__((objc_designated_initializer));
- (CSDKResultStateError *)doCopyError:(CSDKDomainError *)error __attribute__((swift_name("doCopy(error:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKDomainError *error __attribute__((swift_name("error")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResultStateLoading")))
@interface CSDKResultStateLoading : CSDKResultState<CSDKKotlinNothing *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)loading __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKResultStateLoading *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResultStateSuccess")))
@interface CSDKResultStateSuccess<T> : CSDKResultState<T>
- (instancetype)initWithData:(T _Nullable)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
- (CSDKResultStateSuccess<T> *)doCopyData:(T _Nullable)data __attribute__((swift_name("doCopy(data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) T _Nullable data __attribute__((swift_name("data")));
@end

__attribute__((swift_name("TimeProvider")))
@protocol CSDKTimeProvider
@required
- (int64_t)nowEpochMillis __attribute__((swift_name("nowEpochMillis()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SystemTimeProvider")))
@interface CSDKSystemTimeProvider : CSDKBase <CSDKTimeProvider>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (int64_t)nowEpochMillis __attribute__((swift_name("nowEpochMillis()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CachePolicy")))
@interface CSDKCachePolicy : CSDKBase
- (instancetype)initWithTimeProvider:(id<CSDKTimeProvider>)timeProvider ttlMillis:(int64_t)ttlMillis __attribute__((swift_name("init(timeProvider:ttlMillis:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isExpired __attribute__((swift_name("isExpired()")));
- (void)markUpdated __attribute__((swift_name("markUpdated()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CruiseLocalDataSource")))
@interface CSDKCruiseLocalDataSource : CSDKBase
- (instancetype)initWithLocalStore:(id<CSDKLocalStore>)localStore timeProvider:(id<CSDKTimeProvider>)timeProvider __attribute__((swift_name("init(localStore:timeProvider:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)enqueueSyncEntityType:(NSString *)entityType entityId:(NSString *)entityId operationType:(CSDKSyncOperationType *)operationType payload:(NSString *)payload completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("enqueueSync(entityType:entityId:operationType:payload:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getItineraryPage:(int32_t)page pageSize:(int32_t)pageSize completionHandler:(void (^)(NSArray<CSDKItineraryItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getItinerary(page:pageSize:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessageMessageId:(NSString *)messageId completionHandler:(void (^)(CSDKChatMessage * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessage(messageId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMessagesRoomId:(NSString *)roomId completionHandler:(void (^)(NSArray<CSDKChatMessage *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMessages(roomId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrderOrderId:(NSString *)orderId completionHandler:(void (^)(CSDKKitchenOrder * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrder(orderId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOrdersUserId:(NSString *)userId completionHandler:(void (^)(NSArray<CSDKKitchenOrder *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getOrders(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPreferencesUserId:(NSString *)userId completionHandler:(void (^)(CSDKUserPreferences * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getPreferences(userId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSessionWithCompletionHandler:(void (^)(CSDKUserSession * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getSession(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSyncQueueLimit:(int32_t)limit completionHandler:(void (^)(NSArray<CSDKSyncQueueItem *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSyncQueue(limit:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)markOrderPendingOrderId:(NSString *)orderId pendingSync:(BOOL)pendingSync completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("markOrderPending(orderId:pendingSync:completionHandler:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeItinerary __attribute__((swift_name("observeItinerary()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeMessagesRoomId:(NSString *)roomId __attribute__((swift_name("observeMessages(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeOrdersUserId:(NSString *)userId __attribute__((swift_name("observeOrders(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observePreferencesUserId:(NSString *)userId __attribute__((swift_name("observePreferences(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSession __attribute__((swift_name("observeSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeSyncQueue __attribute__((swift_name("observeSyncQueue()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeSyncItemSyncItemId:(NSString *)syncItemId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeSyncItem(syncItemId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveItineraryItems:(NSArray<CSDKItineraryItem *> *)items completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveItinerary(items:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveMessageMessage:(CSDKChatMessage *)message completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveMessage(message:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveMessagesMessages:(NSArray<CSDKChatMessage *> *)messages completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveMessages(messages:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveOrderOrder:(CSDKKitchenOrder *)order completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveOrder(order:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)savePreferencesPreferences:(CSDKUserPreferences *)preferences completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("savePreferences(preferences:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveSessionSession:(CSDKUserSession *)session completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("saveSession(session:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateOrderStatusOrderId:(NSString *)orderId status:(CSDKOrderStatus *)status pendingSync:(BOOL)pendingSync completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("updateOrderStatus(orderId:status:pendingSync:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateSyncItemItem:(CSDKSyncQueueItem *)item completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("updateSyncItem(item:completionHandler:)")));
@end

__attribute__((swift_name("SyncRemoteGateway")))
@protocol CSDKSyncRemoteGateway
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pullRemoteChangesToken:(NSString *)token sinceEpochMillis:(int64_t)sinceEpochMillis completionHandler:(void (^)(NSArray<CSDKRemoteSyncChangeDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("pullRemoteChanges(token:sinceEpochMillis:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pushSyncChangePayload:(NSString *)payload token:(NSString *)token completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pushSyncChange(payload:token:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CruiseRemoteDataSource")))
@interface CSDKCruiseRemoteDataSource : CSDKBase <CSDKSyncRemoteGateway>
- (instancetype)initWithClient:(CSDKKtor_client_coreHttpClient *)client baseUrl:(NSString *)baseUrl __attribute__((swift_name("init(client:baseUrl:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)fetchItineraryPage:(int32_t)page pageSize:(int32_t)pageSize token:(NSString *)token completionHandler:(void (^)(CSDKItineraryPageDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchItinerary(page:pageSize:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)fetchMessagesRoomId:(NSString *)roomId token:(NSString *)token completionHandler:(void (^)(NSArray<CSDKChatMessageDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchMessages(roomId:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)fetchPreferencesUserId:(NSString *)userId token:(NSString *)token completionHandler:(void (^)(CSDKPreferencesDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchPreferences(userId:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loginEmail:(NSString *)email password:(NSString *)password completionHandler:(void (^)(CSDKUserSessionDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("login(email:password:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)placeOrderOrder:(CSDKOrderDto *)order token:(NSString *)token completionHandler:(void (^)(CSDKOrderDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("placeOrder(order:token:completionHandler:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)pollMessagesRoomId:(NSString *)roomId token:(NSString *)token intervalMillis:(int64_t)intervalMillis __attribute__((swift_name("pollMessages(roomId:token:intervalMillis:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pullRemoteChangesToken:(NSString *)token sinceEpochMillis:(int64_t)sinceEpochMillis completionHandler:(void (^)(NSArray<CSDKRemoteSyncChangeDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("pullRemoteChanges(token:sinceEpochMillis:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pushSyncChangePayload:(NSString *)payload token:(NSString *)token completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pushSyncChange(payload:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)savePreferencesPreferences:(CSDKPreferencesDto *)preferences token:(NSString *)token completionHandler:(void (^)(CSDKPreferencesDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("savePreferences(preferences:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendMessageMessage:(CSDKChatMessageDto *)message token:(NSString *)token completionHandler:(void (^)(CSDKChatMessageDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sendMessage(message:token:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateOrderStatusOrderId:(NSString *)orderId status:(NSString *)status token:(NSString *)token completionHandler:(void (^)(CSDKOrderDto * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateOrderStatus(orderId:status:token:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageDto")))
@interface CSDKChatMessageDto : CSDKBase
- (instancetype)initWithId:(NSString *)id roomId:(NSString *)roomId senderId:(NSString *)senderId senderRole:(NSString *)senderRole content:(NSString *)content createdAtEpochMillis:(int64_t)createdAtEpochMillis __attribute__((swift_name("init(id:roomId:senderId:senderRole:content:createdAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKChatMessageDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKChatMessageDto *)doCopyId:(NSString *)id roomId:(NSString *)roomId senderId:(NSString *)senderId senderRole:(NSString *)senderRole content:(NSString *)content createdAtEpochMillis:(int64_t)createdAtEpochMillis __attribute__((swift_name("doCopy(id:roomId:senderId:senderRole:content:createdAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) int64_t createdAtEpochMillis __attribute__((swift_name("createdAtEpochMillis")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSString *roomId __attribute__((swift_name("roomId")));
@property (readonly) NSString *senderId __attribute__((swift_name("senderId")));
@property (readonly) NSString *senderRole __attribute__((swift_name("senderRole")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageDto.Companion")))
@interface CSDKChatMessageDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKChatMessageDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryItemDto")))
@interface CSDKItineraryItemDto : CSDKBase
- (instancetype)initWithId:(NSString *)id day:(int32_t)day title:(NSString *)title description:(NSString *)description startAtEpochMillis:(int64_t)startAtEpochMillis endAtEpochMillis:(int64_t)endAtEpochMillis location:(NSString *)location updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(id:day:title:description:startAtEpochMillis:endAtEpochMillis:location:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKItineraryItemDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKItineraryItemDto *)doCopyId:(NSString *)id day:(int32_t)day title:(NSString *)title description:(NSString *)description startAtEpochMillis:(int64_t)startAtEpochMillis endAtEpochMillis:(int64_t)endAtEpochMillis location:(NSString *)location updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(id:day:title:description:startAtEpochMillis:endAtEpochMillis:location:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t day __attribute__((swift_name("day")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int64_t endAtEpochMillis __attribute__((swift_name("endAtEpochMillis")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSString *location __attribute__((swift_name("location")));
@property (readonly) int64_t startAtEpochMillis __attribute__((swift_name("startAtEpochMillis")));
@property (readonly) NSString *title __attribute__((swift_name("title")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryItemDto.Companion")))
@interface CSDKItineraryItemDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKItineraryItemDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryPageDto")))
@interface CSDKItineraryPageDto : CSDKBase
- (instancetype)initWithPage:(int32_t)page pageSize:(int32_t)pageSize items:(NSArray<CSDKItineraryItemDto *> *)items __attribute__((swift_name("init(page:pageSize:items:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKItineraryPageDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKItineraryPageDto *)doCopyPage:(int32_t)page pageSize:(int32_t)pageSize items:(NSArray<CSDKItineraryItemDto *> *)items __attribute__((swift_name("doCopy(page:pageSize:items:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<CSDKItineraryItemDto *> *items __attribute__((swift_name("items")));
@property (readonly) int32_t page __attribute__((swift_name("page")));
@property (readonly) int32_t pageSize __attribute__((swift_name("pageSize")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryPageDto.Companion")))
@interface CSDKItineraryPageDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKItineraryPageDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginRequestDto")))
@interface CSDKLoginRequestDto : CSDKBase
- (instancetype)initWithEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("init(email:password:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKLoginRequestDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKLoginRequestDto *)doCopyEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("doCopy(email:password:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *email __attribute__((swift_name("email")));
@property (readonly) NSString *password __attribute__((swift_name("password")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginRequestDto.Companion")))
@interface CSDKLoginRequestDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKLoginRequestDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderDto")))
@interface CSDKOrderDto : CSDKBase
- (instancetype)initWithId:(NSString *)id userId:(NSString *)userId items:(NSArray<NSString *> *)items notes:(NSString * _Nullable)notes status:(NSString *)status totalAmount:(double)totalAmount updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(id:userId:items:notes:status:totalAmount:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKOrderDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKOrderDto *)doCopyId:(NSString *)id userId:(NSString *)userId items:(NSArray<NSString *> *)items notes:(NSString * _Nullable)notes status:(NSString *)status totalAmount:(double)totalAmount updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(id:userId:items:notes:status:totalAmount:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSArray<NSString *> *items __attribute__((swift_name("items")));
@property (readonly) NSString * _Nullable notes __attribute__((swift_name("notes")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) double totalAmount __attribute__((swift_name("totalAmount")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderDto.Companion")))
@interface CSDKOrderDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKOrderDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreferencesDto")))
@interface CSDKPreferencesDto : CSDKBase
- (instancetype)initWithUserId:(NSString *)userId favoriteFoods:(NSArray<NSString *> *)favoriteFoods preferredActivities:(NSArray<NSString *> *)preferredActivities roomTemperature:(int32_t)roomTemperature updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(userId:favoriteFoods:preferredActivities:roomTemperature:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKPreferencesDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKPreferencesDto *)doCopyUserId:(NSString *)userId favoriteFoods:(NSArray<NSString *> *)favoriteFoods preferredActivities:(NSArray<NSString *> *)preferredActivities roomTemperature:(int32_t)roomTemperature updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(userId:favoriteFoods:preferredActivities:roomTemperature:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> *favoriteFoods __attribute__((swift_name("favoriteFoods")));
@property (readonly) NSArray<NSString *> *preferredActivities __attribute__((swift_name("preferredActivities")));
@property (readonly) int32_t roomTemperature __attribute__((swift_name("roomTemperature")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreferencesDto.Companion")))
@interface CSDKPreferencesDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKPreferencesDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RemoteSyncChangeDto")))
@interface CSDKRemoteSyncChangeDto : CSDKBase
- (instancetype)initWithEntityType:(NSString *)entityType entityId:(NSString *)entityId operationType:(NSString *)operationType payload:(NSString *)payload updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(entityType:entityId:operationType:payload:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKRemoteSyncChangeDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKRemoteSyncChangeDto *)doCopyEntityType:(NSString *)entityType entityId:(NSString *)entityId operationType:(NSString *)operationType payload:(NSString *)payload updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(entityType:entityId:operationType:payload:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *entityId __attribute__((swift_name("entityId")));
@property (readonly) NSString *entityType __attribute__((swift_name("entityType")));
@property (readonly) NSString *operationType __attribute__((swift_name("operationType")));
@property (readonly) NSString *payload __attribute__((swift_name("payload")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RemoteSyncChangeDto.Companion")))
@interface CSDKRemoteSyncChangeDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKRemoteSyncChangeDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserSessionDto")))
@interface CSDKUserSessionDto : CSDKBase
- (instancetype)initWithUserId:(NSString *)userId email:(NSString *)email token:(NSString *)token refreshToken:(NSString * _Nullable)refreshToken expiresAtEpochMillis:(int64_t)expiresAtEpochMillis lastLoginAtEpochMillis:(int64_t)lastLoginAtEpochMillis __attribute__((swift_name("init(userId:email:token:refreshToken:expiresAtEpochMillis:lastLoginAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKUserSessionDtoCompanion *companion __attribute__((swift_name("companion")));
- (CSDKUserSessionDto *)doCopyUserId:(NSString *)userId email:(NSString *)email token:(NSString *)token refreshToken:(NSString * _Nullable)refreshToken expiresAtEpochMillis:(int64_t)expiresAtEpochMillis lastLoginAtEpochMillis:(int64_t)lastLoginAtEpochMillis __attribute__((swift_name("doCopy(userId:email:token:refreshToken:expiresAtEpochMillis:lastLoginAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *email __attribute__((swift_name("email")));
@property (readonly) int64_t expiresAtEpochMillis __attribute__((swift_name("expiresAtEpochMillis")));
@property (readonly) int64_t lastLoginAtEpochMillis __attribute__((swift_name("lastLoginAtEpochMillis")));
@property (readonly) NSString * _Nullable refreshToken __attribute__((swift_name("refreshToken")));
@property (readonly) NSString *token __attribute__((swift_name("token")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserSessionDto.Companion")))
@interface CSDKUserSessionDtoCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKUserSessionDtoCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("AuthRepository")))
@protocol CSDKAuthRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)getCachedSession __attribute__((swift_name("getCachedSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)loginEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("login(email:password:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthRepositoryImpl")))
@interface CSDKAuthRepositoryImpl : CSDKBase <CSDKAuthRepository>
- (instancetype)initWithRemoteDataSource:(CSDKCruiseRemoteDataSource *)remoteDataSource localDataSource:(CSDKCruiseLocalDataSource *)localDataSource networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider __attribute__((swift_name("init(remoteDataSource:localDataSource:networkMonitor:secureTokenStore:dispatcherProvider:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)getCachedSession __attribute__((swift_name("getCachedSession()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)loginEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("login(email:password:)")));
@end

__attribute__((swift_name("ChatRepository")))
@protocol CSDKChatRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)receiveMessagesRoomId:(NSString *)roomId __attribute__((swift_name("receiveMessages(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)sendMessageMessage:(CSDKChatMessage *)message __attribute__((swift_name("sendMessage(message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatRepositoryImpl")))
@interface CSDKChatRepositoryImpl : CSDKBase <CSDKChatRepository>
- (instancetype)initWithRemoteDataSource:(CSDKCruiseRemoteDataSource *)remoteDataSource localDataSource:(CSDKCruiseLocalDataSource *)localDataSource networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore jsonCodec:(CSDKJsonCodec *)jsonCodec dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider pollingIntervalMillis:(int64_t)pollingIntervalMillis __attribute__((swift_name("init(remoteDataSource:localDataSource:networkMonitor:secureTokenStore:jsonCodec:dispatcherProvider:pollingIntervalMillis:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)receiveMessagesRoomId:(NSString *)roomId __attribute__((swift_name("receiveMessages(roomId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)sendMessageMessage:(CSDKChatMessage *)message __attribute__((swift_name("sendMessage(message:)")));
@end

__attribute__((swift_name("ItineraryRepository")))
@protocol CSDKItineraryRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)fetchItineraryPage:(int32_t)page pageSize:(int32_t)pageSize __attribute__((swift_name("fetchItinerary(page:pageSize:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryRepositoryImpl")))
@interface CSDKItineraryRepositoryImpl : CSDKBase <CSDKItineraryRepository>
- (instancetype)initWithRemoteDataSource:(CSDKCruiseRemoteDataSource *)remoteDataSource localDataSource:(CSDKCruiseLocalDataSource *)localDataSource networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore cachePolicy:(CSDKCachePolicy *)cachePolicy dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider __attribute__((swift_name("init(remoteDataSource:localDataSource:networkMonitor:secureTokenStore:cachePolicy:dispatcherProvider:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)fetchItineraryPage:(int32_t)page pageSize:(int32_t)pageSize __attribute__((swift_name("fetchItinerary(page:pageSize:)")));
@end

__attribute__((swift_name("OrderRepository")))
@protocol CSDKOrderRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)observeOrdersUserId:(NSString *)userId __attribute__((swift_name("observeOrders(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)placeOrderOrder:(CSDKKitchenOrder *)order __attribute__((swift_name("placeOrder(order:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)updateOrderStatusOrderId:(NSString *)orderId status:(CSDKOrderStatus *)status __attribute__((swift_name("updateOrderStatus(orderId:status:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderRepositoryImpl")))
@interface CSDKOrderRepositoryImpl : CSDKBase <CSDKOrderRepository>
- (instancetype)initWithRemoteDataSource:(CSDKCruiseRemoteDataSource *)remoteDataSource localDataSource:(CSDKCruiseLocalDataSource *)localDataSource networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore jsonCodec:(CSDKJsonCodec *)jsonCodec dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider __attribute__((swift_name("init(remoteDataSource:localDataSource:networkMonitor:secureTokenStore:jsonCodec:dispatcherProvider:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)observeOrdersUserId:(NSString *)userId __attribute__((swift_name("observeOrders(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)placeOrderOrder:(CSDKKitchenOrder *)order __attribute__((swift_name("placeOrder(order:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)updateOrderStatusOrderId:(NSString *)orderId status:(CSDKOrderStatus *)status __attribute__((swift_name("updateOrderStatus(orderId:status:)")));
@end

__attribute__((swift_name("PreferencesRepository")))
@protocol CSDKPreferencesRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)fetchPreferencesUserId:(NSString *)userId __attribute__((swift_name("fetchPreferences(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)savePreferencesPreferences:(CSDKUserPreferences *)preferences __attribute__((swift_name("savePreferences(preferences:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PreferencesRepositoryImpl")))
@interface CSDKPreferencesRepositoryImpl : CSDKBase <CSDKPreferencesRepository>
- (instancetype)initWithRemoteDataSource:(CSDKCruiseRemoteDataSource *)remoteDataSource localDataSource:(CSDKCruiseLocalDataSource *)localDataSource networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore jsonCodec:(CSDKJsonCodec *)jsonCodec dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider __attribute__((swift_name("init(remoteDataSource:localDataSource:networkMonitor:secureTokenStore:jsonCodec:dispatcherProvider:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)fetchPreferencesUserId:(NSString *)userId __attribute__((swift_name("fetchPreferences(userId:)")));
- (id<CSDKKotlinx_coroutines_coreFlow>)savePreferencesPreferences:(CSDKUserPreferences *)preferences __attribute__((swift_name("savePreferences(preferences:)")));
@end

__attribute__((swift_name("ConflictResolver")))
@protocol CSDKConflictResolver
@required
- (BOOL)shouldApplyRemoteLocalUpdatedAt:(int64_t)localUpdatedAt remoteUpdatedAt:(int64_t)remoteUpdatedAt __attribute__((swift_name("shouldApplyRemote(localUpdatedAt:remoteUpdatedAt:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LastWriteWinsConflictResolver")))
@interface CSDKLastWriteWinsConflictResolver : CSDKBase <CSDKConflictResolver>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)shouldApplyRemoteLocalUpdatedAt:(int64_t)localUpdatedAt remoteUpdatedAt:(int64_t)remoteUpdatedAt __attribute__((swift_name("shouldApplyRemote(localUpdatedAt:remoteUpdatedAt:)")));
@end

__attribute__((swift_name("SyncRepository")))
@protocol CSDKSyncRepository
@required
- (id<CSDKKotlinx_coroutines_coreFlow>)triggerSync __attribute__((swift_name("triggerSync()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SyncEngine")))
@interface CSDKSyncEngine : CSDKBase <CSDKSyncRepository>
- (instancetype)initWithLocalDataSource:(CSDKCruiseLocalDataSource *)localDataSource remoteDataSource:(id<CSDKSyncRemoteGateway>)remoteDataSource secureTokenStore:(id<CSDKSecureTokenStore>)secureTokenStore networkMonitor:(id<CSDKNetworkMonitor>)networkMonitor jsonCodec:(CSDKJsonCodec *)jsonCodec dispatcherProvider:(id<CSDKDispatcherProvider>)dispatcherProvider timeProvider:(id<CSDKTimeProvider>)timeProvider backoff:(CSDKExponentialBackoff *)backoff conflictResolver:(id<CSDKConflictResolver>)conflictResolver __attribute__((swift_name("init(localDataSource:remoteDataSource:secureTokenStore:networkMonitor:jsonCodec:dispatcherProvider:timeProvider:backoff:conflictResolver:)"))) __attribute__((objc_designated_initializer));
- (void)startScope:(id<CSDKKotlinx_coroutines_coreCoroutineScope>)scope __attribute__((swift_name("start(scope:)")));
- (void)stop __attribute__((swift_name("stop()")));
- (id<CSDKKotlinx_coroutines_coreFlow>)triggerSync __attribute__((swift_name("triggerSync()")));
@end

__attribute__((swift_name("DomainError")))
@interface CSDKDomainError : CSDKBase
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DomainError.CacheError")))
@interface CSDKDomainErrorCacheError : CSDKDomainError
- (instancetype)initWithMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (CSDKDomainErrorCacheError *)doCopyMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("doCopy(message:cause:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DomainError.NetworkError")))
@interface CSDKDomainErrorNetworkError : CSDKDomainError
- (instancetype)initWithMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (CSDKDomainErrorNetworkError *)doCopyMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("doCopy(message:cause:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DomainError.SyncError")))
@interface CSDKDomainErrorSyncError : CSDKDomainError
- (instancetype)initWithMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (CSDKDomainErrorSyncError *)doCopyMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("doCopy(message:cause:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DomainError.UnauthorizedError")))
@interface CSDKDomainErrorUnauthorizedError : CSDKDomainError
- (instancetype)initWithMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (CSDKDomainErrorUnauthorizedError *)doCopyMessage:(NSString *)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("doCopy(message:cause:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage")))
@interface CSDKChatMessage : CSDKBase
- (instancetype)initWithId:(NSString *)id roomId:(NSString *)roomId senderId:(NSString *)senderId senderRole:(NSString *)senderRole content:(NSString *)content createdAtEpochMillis:(int64_t)createdAtEpochMillis pendingSync:(BOOL)pendingSync __attribute__((swift_name("init(id:roomId:senderId:senderRole:content:createdAtEpochMillis:pendingSync:)"))) __attribute__((objc_designated_initializer));
- (CSDKChatMessage *)doCopyId:(NSString *)id roomId:(NSString *)roomId senderId:(NSString *)senderId senderRole:(NSString *)senderRole content:(NSString *)content createdAtEpochMillis:(int64_t)createdAtEpochMillis pendingSync:(BOOL)pendingSync __attribute__((swift_name("doCopy(id:roomId:senderId:senderRole:content:createdAtEpochMillis:pendingSync:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) int64_t createdAtEpochMillis __attribute__((swift_name("createdAtEpochMillis")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) BOOL pendingSync __attribute__((swift_name("pendingSync")));
@property (readonly) NSString *roomId __attribute__((swift_name("roomId")));
@property (readonly) NSString *senderId __attribute__((swift_name("senderId")));
@property (readonly) NSString *senderRole __attribute__((swift_name("senderRole")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ItineraryItem")))
@interface CSDKItineraryItem : CSDKBase
- (instancetype)initWithId:(NSString *)id day:(int32_t)day title:(NSString *)title description:(NSString *)description startAt:(CSDKKotlinx_datetimeInstant *)startAt endAt:(CSDKKotlinx_datetimeInstant *)endAt location:(NSString *)location updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(id:day:title:description:startAt:endAt:location:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
- (CSDKItineraryItem *)doCopyId:(NSString *)id day:(int32_t)day title:(NSString *)title description:(NSString *)description startAt:(CSDKKotlinx_datetimeInstant *)startAt endAt:(CSDKKotlinx_datetimeInstant *)endAt location:(NSString *)location updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(id:day:title:description:startAt:endAt:location:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t day __attribute__((swift_name("day")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) CSDKKotlinx_datetimeInstant *endAt __attribute__((swift_name("endAt")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSString *location __attribute__((swift_name("location")));
@property (readonly) CSDKKotlinx_datetimeInstant *startAt __attribute__((swift_name("startAt")));
@property (readonly) NSString *title __attribute__((swift_name("title")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KitchenOrder")))
@interface CSDKKitchenOrder : CSDKBase
- (instancetype)initWithId:(NSString *)id userId:(NSString *)userId items:(NSArray<NSString *> *)items notes:(NSString * _Nullable)notes status:(CSDKOrderStatus *)status totalAmount:(double)totalAmount updatedAtEpochMillis:(int64_t)updatedAtEpochMillis pendingSync:(BOOL)pendingSync __attribute__((swift_name("init(id:userId:items:notes:status:totalAmount:updatedAtEpochMillis:pendingSync:)"))) __attribute__((objc_designated_initializer));
- (CSDKKitchenOrder *)doCopyId:(NSString *)id userId:(NSString *)userId items:(NSArray<NSString *> *)items notes:(NSString * _Nullable)notes status:(CSDKOrderStatus *)status totalAmount:(double)totalAmount updatedAtEpochMillis:(int64_t)updatedAtEpochMillis pendingSync:(BOOL)pendingSync __attribute__((swift_name("doCopy(id:userId:items:notes:status:totalAmount:updatedAtEpochMillis:pendingSync:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSArray<NSString *> *items __attribute__((swift_name("items")));
@property (readonly) NSString * _Nullable notes __attribute__((swift_name("notes")));
@property (readonly) BOOL pendingSync __attribute__((swift_name("pendingSync")));
@property (readonly) CSDKOrderStatus *status __attribute__((swift_name("status")));
@property (readonly) double totalAmount __attribute__((swift_name("totalAmount")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol CSDKKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface CSDKKotlinEnum<E> : CSDKBase <CSDKKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OrderStatus")))
@interface CSDKOrderStatus : CSDKKotlinEnum<CSDKOrderStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) CSDKOrderStatus *queued __attribute__((swift_name("queued")));
@property (class, readonly) CSDKOrderStatus *confirmed __attribute__((swift_name("confirmed")));
@property (class, readonly) CSDKOrderStatus *preparing __attribute__((swift_name("preparing")));
@property (class, readonly) CSDKOrderStatus *ready __attribute__((swift_name("ready")));
@property (class, readonly) CSDKOrderStatus *delivered __attribute__((swift_name("delivered")));
@property (class, readonly) CSDKOrderStatus *cancelled __attribute__((swift_name("cancelled")));
+ (CSDKKotlinArray<CSDKOrderStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<CSDKOrderStatus *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SyncOperationType")))
@interface CSDKSyncOperationType : CSDKKotlinEnum<CSDKSyncOperationType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) CSDKSyncOperationType *create __attribute__((swift_name("create")));
@property (class, readonly) CSDKSyncOperationType *update __attribute__((swift_name("update")));
@property (class, readonly) CSDKSyncOperationType *delete_ __attribute__((swift_name("delete_")));
+ (CSDKKotlinArray<CSDKSyncOperationType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<CSDKSyncOperationType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SyncQueueItem")))
@interface CSDKSyncQueueItem : CSDKBase
- (instancetype)initWithId:(NSString *)id entityType:(NSString *)entityType entityId:(NSString *)entityId operationType:(CSDKSyncOperationType *)operationType payload:(NSString *)payload timestampEpochMillis:(int64_t)timestampEpochMillis retryCount:(int32_t)retryCount nextRetryEpochMillis:(int64_t)nextRetryEpochMillis __attribute__((swift_name("init(id:entityType:entityId:operationType:payload:timestampEpochMillis:retryCount:nextRetryEpochMillis:)"))) __attribute__((objc_designated_initializer));
- (CSDKSyncQueueItem *)doCopyId:(NSString *)id entityType:(NSString *)entityType entityId:(NSString *)entityId operationType:(CSDKSyncOperationType *)operationType payload:(NSString *)payload timestampEpochMillis:(int64_t)timestampEpochMillis retryCount:(int32_t)retryCount nextRetryEpochMillis:(int64_t)nextRetryEpochMillis __attribute__((swift_name("doCopy(id:entityType:entityId:operationType:payload:timestampEpochMillis:retryCount:nextRetryEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *entityId __attribute__((swift_name("entityId")));
@property (readonly) NSString *entityType __attribute__((swift_name("entityType")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) int64_t nextRetryEpochMillis __attribute__((swift_name("nextRetryEpochMillis")));
@property (readonly) CSDKSyncOperationType *operationType __attribute__((swift_name("operationType")));
@property (readonly) NSString *payload __attribute__((swift_name("payload")));
@property (readonly) int32_t retryCount __attribute__((swift_name("retryCount")));
@property (readonly) int64_t timestampEpochMillis __attribute__((swift_name("timestampEpochMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserPreferences")))
@interface CSDKUserPreferences : CSDKBase
- (instancetype)initWithUserId:(NSString *)userId favoriteFoods:(NSArray<NSString *> *)favoriteFoods preferredActivities:(NSArray<NSString *> *)preferredActivities roomTemperature:(int32_t)roomTemperature updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("init(userId:favoriteFoods:preferredActivities:roomTemperature:updatedAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
- (CSDKUserPreferences *)doCopyUserId:(NSString *)userId favoriteFoods:(NSArray<NSString *> *)favoriteFoods preferredActivities:(NSArray<NSString *> *)preferredActivities roomTemperature:(int32_t)roomTemperature updatedAtEpochMillis:(int64_t)updatedAtEpochMillis __attribute__((swift_name("doCopy(userId:favoriteFoods:preferredActivities:roomTemperature:updatedAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> *favoriteFoods __attribute__((swift_name("favoriteFoods")));
@property (readonly) NSArray<NSString *> *preferredActivities __attribute__((swift_name("preferredActivities")));
@property (readonly) int32_t roomTemperature __attribute__((swift_name("roomTemperature")));
@property (readonly) int64_t updatedAtEpochMillis __attribute__((swift_name("updatedAtEpochMillis")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserSession")))
@interface CSDKUserSession : CSDKBase
- (instancetype)initWithUserId:(NSString *)userId email:(NSString *)email token:(NSString *)token refreshToken:(NSString * _Nullable)refreshToken expiresAtEpochMillis:(int64_t)expiresAtEpochMillis lastLoginAtEpochMillis:(int64_t)lastLoginAtEpochMillis __attribute__((swift_name("init(userId:email:token:refreshToken:expiresAtEpochMillis:lastLoginAtEpochMillis:)"))) __attribute__((objc_designated_initializer));
- (CSDKUserSession *)doCopyUserId:(NSString *)userId email:(NSString *)email token:(NSString *)token refreshToken:(NSString * _Nullable)refreshToken expiresAtEpochMillis:(int64_t)expiresAtEpochMillis lastLoginAtEpochMillis:(int64_t)lastLoginAtEpochMillis __attribute__((swift_name("doCopy(userId:email:token:refreshToken:expiresAtEpochMillis:lastLoginAtEpochMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *email __attribute__((swift_name("email")));
@property (readonly) int64_t expiresAtEpochMillis __attribute__((swift_name("expiresAtEpochMillis")));
@property (readonly) BOOL isExpired __attribute__((swift_name("isExpired")));
@property (readonly) int64_t lastLoginAtEpochMillis __attribute__((swift_name("lastLoginAtEpochMillis")));
@property (readonly) NSString * _Nullable refreshToken __attribute__((swift_name("refreshToken")));
@property (readonly) NSString *token __attribute__((swift_name("token")));
@property (readonly) NSString *userId __attribute__((swift_name("userId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FetchItineraryUseCase")))
@interface CSDKFetchItineraryUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKItineraryRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokePage:(int32_t)page pageSize:(int32_t)pageSize __attribute__((swift_name("invoke(page:pageSize:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FetchPreferencesUseCase")))
@interface CSDKFetchPreferencesUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKPreferencesRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeUserId:(NSString *)userId __attribute__((swift_name("invoke(userId:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GetCachedSessionUseCase")))
@interface CSDKGetCachedSessionUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKAuthRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invoke __attribute__((swift_name("invoke()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginUseCase")))
@interface CSDKLoginUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKAuthRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeEmail:(NSString *)email password:(NSString *)password __attribute__((swift_name("invoke(email:password:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ObserveOrdersUseCase")))
@interface CSDKObserveOrdersUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKOrderRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeUserId:(NSString *)userId __attribute__((swift_name("invoke(userId:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaceOrderUseCase")))
@interface CSDKPlaceOrderUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKOrderRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeOrder:(CSDKKitchenOrder *)order __attribute__((swift_name("invoke(order:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReceiveMessagesUseCase")))
@interface CSDKReceiveMessagesUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKChatRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeRoomId:(NSString *)roomId __attribute__((swift_name("invoke(roomId:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SavePreferencesUseCase")))
@interface CSDKSavePreferencesUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKPreferencesRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokePreferences:(CSDKUserPreferences *)preferences __attribute__((swift_name("invoke(preferences:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SendMessageUseCase")))
@interface CSDKSendMessageUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKChatRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeMessage:(CSDKChatMessage *)message __attribute__((swift_name("invoke(message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TriggerSyncUseCase")))
@interface CSDKTriggerSyncUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKSyncRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invoke __attribute__((swift_name("invoke()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UpdateOrderStatusUseCase")))
@interface CSDKUpdateOrderStatusUseCase : CSDKBase
- (instancetype)initWithRepository:(id<CSDKOrderRepository>)repository __attribute__((swift_name("init(repository:)"))) __attribute__((objc_designated_initializer));
- (id<CSDKKotlinx_coroutines_coreFlow>)invokeOrderId:(NSString *)orderId status:(CSDKOrderStatus *)status __attribute__((swift_name("invoke(orderId:status:)")));
@end

@interface CSDKChatMessageDto (Extensions)
- (CSDKChatMessage *)toDomainPendingSync:(BOOL)pendingSync __attribute__((swift_name("toDomain(pendingSync:)")));
@end

@interface CSDKItineraryItemDto (Extensions)
- (CSDKItineraryItem *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface CSDKOrderDto (Extensions)
- (CSDKKitchenOrder *)toDomainPendingSync:(BOOL)pendingSync __attribute__((swift_name("toDomain(pendingSync:)")));
@end

@interface CSDKPreferencesDto (Extensions)
- (CSDKUserPreferences *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface CSDKUserSessionDto (Extensions)
- (CSDKUserSession *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface CSDKChatMessage (Extensions)
- (CSDKChatMessageDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface CSDKItineraryItem (Extensions)
- (CSDKItineraryItemDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface CSDKKitchenOrder (Extensions)
- (CSDKOrderDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface CSDKUserPreferences (Extensions)
- (CSDKPreferencesDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface CSDKUserSession (Extensions)
- (CSDKUserSessionDto *)toDto __attribute__((swift_name("toDto()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceInfoProvider_iosKt")))
@interface CSDKDeviceInfoProvider_iosKt : CSDKBase
+ (id<CSDKDeviceInfoProvider>)createDeviceInfoProvider __attribute__((swift_name("createDeviceInfoProvider()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileSystemProvider_iosKt")))
@interface CSDKFileSystemProvider_iosKt : CSDKBase
+ (id<CSDKFileSystemProvider>)createFileSystemProvider __attribute__((swift_name("createFileSystemProvider()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkModuleKt")))
@interface CSDKNetworkModuleKt : CSDKBase
+ (CSDKKtor_client_coreHttpClient *)createCruiseHttpClientEnableLogs:(BOOL)enableLogs __attribute__((swift_name("createCruiseHttpClient(enableLogs:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkMonitorFactory_iosKt")))
@interface CSDKNetworkMonitorFactory_iosKt : CSDKBase
+ (id<CSDKNetworkMonitor>)createPlatformNetworkMonitor __attribute__((swift_name("createPlatformNetworkMonitor()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlatformLogger_iosKt")))
@interface CSDKPlatformLogger_iosKt : CSDKBase
+ (id<CSDKPlatformLogger>)createPlatformLoggerTag:(NSString *)tag __attribute__((swift_name("createPlatformLogger(tag:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SampleUsageKt")))
@interface CSDKSampleUsageKt : CSDKBase
+ (void)sampleSdkUsage __attribute__((swift_name("sampleSdkUsage()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureTokenStoreFactory_iosKt")))
@interface CSDKSecureTokenStoreFactory_iosKt : CSDKBase
+ (id<CSDKSecureTokenStore>)createSecureTokenStore __attribute__((swift_name("createSecureTokenStore()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol CSDKKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<CSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol CSDKKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<CSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Ktor_ioCloseable")))
@protocol CSDKKtor_ioCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClient")))
@interface CSDKKtor_client_coreHttpClient : CSDKBase <CSDKKotlinx_coroutines_coreCoroutineScope, CSDKKtor_ioCloseable>
- (instancetype)initWithEngine:(id<CSDKKtor_client_coreHttpClientEngine>)engine userConfig:(CSDKKtor_client_coreHttpClientConfig<CSDKKtor_client_coreHttpClientEngineConfig *> *)userConfig __attribute__((swift_name("init(engine:userConfig:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (CSDKKtor_client_coreHttpClient *)configBlock:(void (^)(CSDKKtor_client_coreHttpClientConfig<id> *))block __attribute__((swift_name("config(block:)")));
- (BOOL)isSupportedCapability:(id<CSDKKtor_client_coreHttpClientEngineCapability>)capability __attribute__((swift_name("isSupported(capability:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) id<CSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<CSDKKtor_client_coreHttpClientEngine> engine __attribute__((swift_name("engine")));
@property (readonly) CSDKKtor_client_coreHttpClientEngineConfig *engineConfig __attribute__((swift_name("engineConfig")));
@property (readonly) CSDKKtor_eventsEvents *monitor __attribute__((swift_name("monitor")));
@property (readonly) CSDKKtor_client_coreHttpReceivePipeline *receivePipeline __attribute__((swift_name("receivePipeline")));
@property (readonly) CSDKKtor_client_coreHttpRequestPipeline *requestPipeline __attribute__((swift_name("requestPipeline")));
@property (readonly) CSDKKtor_client_coreHttpResponsePipeline *responsePipeline __attribute__((swift_name("responsePipeline")));
@property (readonly) CSDKKtor_client_coreHttpSendPipeline *sendPipeline __attribute__((swift_name("sendPipeline")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface CSDKKotlinThrowable : CSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (CSDKKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface CSDKKotlinException : CSDKKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface CSDKKotlinRuntimeException : CSDKKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface CSDKKotlinIllegalStateException : CSDKKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface CSDKKotlinCancellationException : CSDKKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol CSDKKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<CSDKKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<CSDKKotlinCoroutineContextElement> _Nullable)getKey:(id<CSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<CSDKKotlinCoroutineContext>)minusKeyKey:(id<CSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<CSDKKotlinCoroutineContext>)plusContext:(id<CSDKKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol CSDKKotlinCoroutineContextElement <CSDKKotlinCoroutineContext>
@required
@property (readonly) id<CSDKKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface CSDKKotlinAbstractCoroutineContextElement : CSDKBase <CSDKKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<CSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<CSDKKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol CSDKKotlinContinuationInterceptor <CSDKKotlinCoroutineContextElement>
@required
- (id<CSDKKotlinContinuation>)interceptContinuationContinuation:(id<CSDKKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<CSDKKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface CSDKKotlinx_coroutines_coreCoroutineDispatcher : CSDKKotlinAbstractCoroutineContextElement <CSDKKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<CSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<CSDKKotlinCoroutineContext>)context block:(id<CSDKKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));
- (void)dispatchYieldContext:(id<CSDKKotlinCoroutineContext>)context block:(id<CSDKKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<CSDKKotlinContinuation>)interceptContinuationContinuation:(id<CSDKKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<CSDKKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (CSDKKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism __attribute__((swift_name("limitedParallelism(parallelism:)")));
- (CSDKKotlinx_coroutines_coreCoroutineDispatcher *)plusOther:(CSDKKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<CSDKKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol CSDKKotlinx_coroutines_coreSharedFlow <CSDKKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreStateFlow")))
@protocol CSDKKotlinx_coroutines_coreStateFlow <CSDKKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialFormat")))
@protocol CSDKKotlinx_serialization_coreSerialFormat
@required
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreStringFormat")))
@protocol CSDKKotlinx_serialization_coreStringFormat <CSDKKotlinx_serialization_coreSerialFormat>
@required
- (id _Nullable)decodeFromStringDeserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (NSString *)encodeToStringSerializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_jsonJson")))
@interface CSDKKotlinx_serialization_jsonJson : CSDKBase <CSDKKotlinx_serialization_coreStringFormat>
@property (class, readonly, getter=companion) CSDKKotlinx_serialization_jsonJsonDefault *companion __attribute__((swift_name("companion")));
- (id _Nullable)decodeFromJsonElementDeserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer element:(CSDKKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("decodeFromJsonElement(deserializer:element:)")));
- (id _Nullable)decodeFromStringString:(NSString *)string __attribute__((swift_name("decodeFromString(string:)")));
- (id _Nullable)decodeFromStringDeserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (CSDKKotlinx_serialization_jsonJsonElement *)encodeToJsonElementSerializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToJsonElement(serializer:value:)")));
- (NSString *)encodeToStringSerializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
- (CSDKKotlinx_serialization_jsonJsonElement *)parseToJsonElementString:(NSString *)string __attribute__((swift_name("parseToJsonElement(string:)")));
@property (readonly) CSDKKotlinx_serialization_jsonJsonConfiguration *configuration __attribute__((swift_name("configuration")));
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol CSDKKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<CSDKKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<CSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol CSDKKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<CSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<CSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol CSDKKotlinx_serialization_coreKSerializer <CSDKKotlinx_serialization_coreSerializationStrategy, CSDKKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface CSDKKotlinNothing : CSDKBase
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/InstantIso8601Serializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant")))
@interface CSDKKotlinx_datetimeInstant : CSDKBase <CSDKKotlinComparable>
@property (class, readonly, getter=companion) CSDKKotlinx_datetimeInstantCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(CSDKKotlinx_datetimeInstant *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (CSDKKotlinx_datetimeInstant *)minusDuration:(int64_t)duration __attribute__((swift_name("minus(duration:)")));
- (int64_t)minusOther:(CSDKKotlinx_datetimeInstant *)other __attribute__((swift_name("minus(other:)")));
- (CSDKKotlinx_datetimeInstant *)plusDuration:(int64_t)duration __attribute__((swift_name("plus(duration:)")));
- (int64_t)toEpochMilliseconds __attribute__((swift_name("toEpochMilliseconds()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t epochSeconds __attribute__((swift_name("epochSeconds")));
@property (readonly) int32_t nanosecondsOfSecond __attribute__((swift_name("nanosecondsOfSecond")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface CSDKKotlinEnumCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface CSDKKotlinArray<T> : CSDKBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(CSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<CSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol CSDKKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngine")))
@protocol CSDKKtor_client_coreHttpClientEngine <CSDKKotlinx_coroutines_coreCoroutineScope, CSDKKtor_ioCloseable>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeData:(CSDKKtor_client_coreHttpRequestData *)data completionHandler:(void (^)(CSDKKtor_client_coreHttpResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(data:completionHandler:)")));
- (void)installClient:(CSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));
@property (readonly) CSDKKtor_client_coreHttpClientEngineConfig *config __attribute__((swift_name("config")));
@property (readonly) CSDKKotlinx_coroutines_coreCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));
@property (readonly) NSSet<id<CSDKKtor_client_coreHttpClientEngineCapability>> *supportedCapabilities __attribute__((swift_name("supportedCapabilities")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngineConfig")))
@interface CSDKKtor_client_coreHttpClientEngineConfig : CSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property BOOL pipelining __attribute__((swift_name("pipelining")));
@property CSDKKtor_client_coreProxyConfig * _Nullable proxy __attribute__((swift_name("proxy")));
@property int32_t threadsCount __attribute__((swift_name("threadsCount"))) __attribute__((deprecated("The [threadsCount] property is deprecated. The [Dispatchers.IO] is used by default.")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientConfig")))
@interface CSDKKtor_client_coreHttpClientConfig<T> : CSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (CSDKKtor_client_coreHttpClientConfig<T> *)clone __attribute__((swift_name("clone()")));
- (void)engineBlock:(void (^)(T))block __attribute__((swift_name("engine(block:)")));
- (void)installClient:(CSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));
- (void)installPlugin:(id<CSDKKtor_client_coreHttpClientPlugin>)plugin configure:(void (^)(id))configure __attribute__((swift_name("install(plugin:configure:)")));
- (void)installKey:(NSString *)key block:(void (^)(CSDKKtor_client_coreHttpClient *))block __attribute__((swift_name("install(key:block:)")));
- (void)plusAssignOther:(CSDKKtor_client_coreHttpClientConfig<T> *)other __attribute__((swift_name("plusAssign(other:)")));
@property BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));
@property BOOL followRedirects __attribute__((swift_name("followRedirects")));
@property BOOL useDefaultTransformers __attribute__((swift_name("useDefaultTransformers")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientEngineCapability")))
@protocol CSDKKtor_client_coreHttpClientEngineCapability
@required
@end

__attribute__((swift_name("Ktor_utilsAttributes")))
@protocol CSDKKtor_utilsAttributes
@required
- (id)computeIfAbsentKey:(CSDKKtor_utilsAttributeKey<id> *)key block:(id (^)(void))block __attribute__((swift_name("computeIfAbsent(key:block:)")));
- (BOOL)containsKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("contains(key:)")));
- (id)getKey_:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("get(key_:)")));
- (id _Nullable)getOrNullKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getOrNull(key:)")));
- (void)putKey:(CSDKKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("put(key:value:)")));
- (void)removeKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("remove(key:)")));
- (id)takeKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("take(key:)")));
- (id _Nullable)takeOrNullKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("takeOrNull(key:)")));
@property (readonly) NSArray<CSDKKtor_utilsAttributeKey<id> *> *allKeys __attribute__((swift_name("allKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_eventsEvents")))
@interface CSDKKtor_eventsEvents : CSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)raiseDefinition:(CSDKKtor_eventsEventDefinition<id> *)definition value:(id _Nullable)value __attribute__((swift_name("raise(definition:value:)")));
- (id<CSDKKotlinx_coroutines_coreDisposableHandle>)subscribeDefinition:(CSDKKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("subscribe(definition:handler:)")));
- (void)unsubscribeDefinition:(CSDKKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("unsubscribe(definition:handler:)")));
@end

__attribute__((swift_name("Ktor_utilsPipeline")))
@interface CSDKKtor_utilsPipeline<TSubject, TContext> : CSDKBase
- (instancetype)initWithPhases:(CSDKKotlinArray<CSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhase:(CSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer));
- (void)addPhasePhase:(CSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("addPhase(phase:)")));
- (void)afterIntercepted __attribute__((swift_name("afterIntercepted()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeContext:(TContext)context subject:(TSubject)subject completionHandler:(void (^)(TSubject _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(context:subject:completionHandler:)")));
- (void)insertPhaseAfterReference:(CSDKKtor_utilsPipelinePhase *)reference phase:(CSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseAfter(reference:phase:)")));
- (void)insertPhaseBeforeReference:(CSDKKtor_utilsPipelinePhase *)reference phase:(CSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseBefore(reference:phase:)")));
- (void)interceptPhase:(CSDKKtor_utilsPipelinePhase *)phase block:(id<CSDKKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(phase:block:)")));
- (NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptorsForPhasePhase:(CSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("interceptorsForPhase(phase:)")));
- (void)mergeFrom:(CSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("merge(from:)")));
- (void)mergePhasesFrom:(CSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("mergePhases(from:)")));
- (void)resetFromFrom:(CSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("resetFrom(from:)")));
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<CSDKKtor_utilsPipelinePhase *> *items __attribute__((swift_name("items")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline")))
@interface CSDKKtor_client_coreHttpReceivePipeline : CSDKKtor_utilsPipeline<CSDKKtor_client_coreHttpResponse *, CSDKKotlinUnit *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(CSDKKotlinArray<CSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(CSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpReceivePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline")))
@interface CSDKKtor_client_coreHttpRequestPipeline : CSDKKtor_utilsPipeline<id, CSDKKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(CSDKKotlinArray<CSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(CSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpRequestPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline")))
@interface CSDKKtor_client_coreHttpResponsePipeline : CSDKKtor_utilsPipeline<CSDKKtor_client_coreHttpResponseContainer *, CSDKKtor_client_coreHttpClientCall *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(CSDKKotlinArray<CSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(CSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpResponsePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline")))
@interface CSDKKtor_client_coreHttpSendPipeline : CSDKKtor_utilsPipeline<id, CSDKKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(CSDKKotlinArray<CSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(CSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<CSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpSendPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol CSDKKotlinCoroutineContextKey
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol CSDKKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<CSDKKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface CSDKKotlinAbstractCoroutineContextKey<B, E> : CSDKBase <CSDKKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<CSDKKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<CSDKKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface CSDKKotlinx_coroutines_coreCoroutineDispatcherKey : CSDKKotlinAbstractCoroutineContextKey<id<CSDKKotlinContinuationInterceptor>, CSDKKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<CSDKKotlinCoroutineContextKey>)baseKey safeCast:(id<CSDKKotlinCoroutineContextElement> _Nullable (^)(id<CSDKKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol CSDKKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface CSDKKotlinx_serialization_coreSerializersModule : CSDKBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<CSDKKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<CSDKKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<CSDKKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<CSDKKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<CSDKKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<CSDKKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<CSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<CSDKKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJson.Default")))
@interface CSDKKotlinx_serialization_jsonJsonDefault : CSDKKotlinx_serialization_jsonJson
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)default_ __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinx_serialization_jsonJsonDefault *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface CSDKKotlinx_serialization_jsonJsonElement : CSDKBase
@property (class, readonly, getter=companion) CSDKKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonConfiguration")))
@interface CSDKKotlinx_serialization_jsonJsonConfiguration : CSDKBase
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL allowComments __attribute__((swift_name("allowComments")));
@property (readonly) BOOL allowSpecialFloatingPointValues __attribute__((swift_name("allowSpecialFloatingPointValues")));
@property (readonly) BOOL allowStructuredMapKeys __attribute__((swift_name("allowStructuredMapKeys")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL allowTrailingComma __attribute__((swift_name("allowTrailingComma")));
@property (readonly) NSString *classDiscriminator __attribute__((swift_name("classDiscriminator")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property CSDKKotlinx_serialization_jsonClassDiscriminatorMode *classDiscriminatorMode __attribute__((swift_name("classDiscriminatorMode")));
@property (readonly) BOOL coerceInputValues __attribute__((swift_name("coerceInputValues")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL decodeEnumsCaseInsensitive __attribute__((swift_name("decodeEnumsCaseInsensitive")));
@property (readonly) BOOL encodeDefaults __attribute__((swift_name("encodeDefaults")));
@property (readonly) BOOL explicitNulls __attribute__((swift_name("explicitNulls")));
@property (readonly) BOOL ignoreUnknownKeys __attribute__((swift_name("ignoreUnknownKeys")));
@property (readonly) BOOL isLenient __attribute__((swift_name("isLenient")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) id<CSDKKotlinx_serialization_jsonJsonNamingStrategy> _Nullable namingStrategy __attribute__((swift_name("namingStrategy")));
@property (readonly) BOOL prettyPrint __attribute__((swift_name("prettyPrint")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *prettyPrintIndent __attribute__((swift_name("prettyPrintIndent")));
@property (readonly) BOOL useAlternativeNames __attribute__((swift_name("useAlternativeNames")));
@property (readonly) BOOL useArrayPolymorphism __attribute__((swift_name("useArrayPolymorphism")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol CSDKKotlinx_serialization_coreEncoder
@required
- (id<CSDKKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<CSDKKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<CSDKKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol CSDKKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<CSDKKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<CSDKKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<CSDKKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) CSDKKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol CSDKKotlinx_serialization_coreDecoder
@required
- (id<CSDKKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<CSDKKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (CSDKKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant.Companion")))
@interface CSDKKotlinx_datetimeInstantCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinx_datetimeInstantCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKotlinx_datetimeInstant *)fromEpochMillisecondsEpochMilliseconds:(int64_t)epochMilliseconds __attribute__((swift_name("fromEpochMilliseconds(epochMilliseconds:)")));
- (CSDKKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment:(int32_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment:)")));
- (CSDKKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment_:(int64_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment_:)")));
- (CSDKKotlinx_datetimeInstant *)now __attribute__((swift_name("now()"))) __attribute__((unavailable("Use Clock.System.now() instead")));
- (CSDKKotlinx_datetimeInstant *)parseInput:(id)input format:(id<CSDKKotlinx_datetimeDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) CSDKKotlinx_datetimeInstant *DISTANT_FUTURE __attribute__((swift_name("DISTANT_FUTURE")));
@property (readonly) CSDKKotlinx_datetimeInstant *DISTANT_PAST __attribute__((swift_name("DISTANT_PAST")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol CSDKKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestData")))
@interface CSDKKtor_client_coreHttpRequestData : CSDKBase
- (instancetype)initWithUrl:(CSDKKtor_httpUrl *)url method:(CSDKKtor_httpHttpMethod *)method headers:(id<CSDKKtor_httpHeaders>)headers body:(CSDKKtor_httpOutgoingContent *)body executionContext:(id<CSDKKotlinx_coroutines_coreJob>)executionContext attributes:(id<CSDKKtor_utilsAttributes>)attributes __attribute__((swift_name("init(url:method:headers:body:executionContext:attributes:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)getCapabilityOrNullKey:(id<CSDKKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) CSDKKtor_httpOutgoingContent *body __attribute__((swift_name("body")));
@property (readonly) id<CSDKKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) id<CSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) CSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) CSDKKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseData")))
@interface CSDKKtor_client_coreHttpResponseData : CSDKBase
- (instancetype)initWithStatusCode:(CSDKKtor_httpHttpStatusCode *)statusCode requestTime:(CSDKKtor_utilsGMTDate *)requestTime headers:(id<CSDKKtor_httpHeaders>)headers version:(CSDKKtor_httpHttpProtocolVersion *)version body:(id)body callContext:(id<CSDKKotlinCoroutineContext>)callContext __attribute__((swift_name("init(statusCode:requestTime:headers:version:body:callContext:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id body __attribute__((swift_name("body")));
@property (readonly) id<CSDKKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<CSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) CSDKKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) CSDKKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) CSDKKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreProxyConfig")))
@interface CSDKKtor_client_coreProxyConfig : CSDKBase
- (instancetype)initWithUrl:(CSDKKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientPlugin")))
@protocol CSDKKtor_client_coreHttpClientPlugin
@required
- (void)installPlugin:(id)plugin scope:(CSDKKtor_client_coreHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (id)prepareBlock:(void (^)(id))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) CSDKKtor_utilsAttributeKey<id> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsAttributeKey")))
@interface CSDKKtor_utilsAttributeKey<T> : CSDKBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_eventsEventDefinition")))
@interface CSDKKtor_eventsEventDefinition<T> : CSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol CSDKKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsPipelinePhase")))
@interface CSDKKtor_utilsPipelinePhase : CSDKBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol CSDKKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction2")))
@protocol CSDKKotlinSuspendFunction2 <CSDKKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline.Phases")))
@interface CSDKKtor_client_coreHttpReceivePipelinePhases : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpReceivePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) CSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((swift_name("Ktor_httpHttpMessage")))
@protocol CSDKKtor_httpHttpMessage
@required
@property (readonly) id<CSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@end

__attribute__((swift_name("Ktor_client_coreHttpResponse")))
@interface CSDKKtor_client_coreHttpResponse : CSDKBase <CSDKKtor_httpHttpMessage, CSDKKotlinx_coroutines_coreCoroutineScope>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<CSDKKtor_ioByteReadChannel> content __attribute__((swift_name("content")));
@property (readonly) CSDKKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) CSDKKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) CSDKKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface CSDKKotlinUnit : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline.Phases")))
@interface CSDKKtor_client_coreHttpRequestPipelinePhases : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpRequestPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Render __attribute__((swift_name("Render")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Send __attribute__((swift_name("Send")));
@property (readonly) CSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((swift_name("Ktor_httpHttpMessageBuilder")))
@protocol CSDKKtor_httpHttpMessageBuilder
@required
@property (readonly) CSDKKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder")))
@interface CSDKKtor_client_coreHttpRequestBuilder : CSDKBase <CSDKKtor_httpHttpMessageBuilder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpRequestBuilderCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_client_coreHttpRequestData *)build __attribute__((swift_name("build()")));
- (id _Nullable)getCapabilityOrNullKey:(id<CSDKKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (void)setAttributesBlock:(void (^)(id<CSDKKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));
- (void)setCapabilityKey:(id<CSDKKtor_client_coreHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));
- (CSDKKtor_client_coreHttpRequestBuilder *)takeFromBuilder:(CSDKKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFrom(builder:)")));
- (CSDKKtor_client_coreHttpRequestBuilder *)takeFromWithExecutionContextBuilder:(CSDKKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFromWithExecutionContext(builder:)")));
- (void)urlBlock:(void (^)(CSDKKtor_httpURLBuilder *, CSDKKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property id body __attribute__((swift_name("body")));
@property CSDKKtor_utilsTypeInfo * _Nullable bodyType __attribute__((swift_name("bodyType")));
@property (readonly) id<CSDKKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) CSDKKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@property CSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) CSDKKtor_httpURLBuilder *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline.Phases")))
@interface CSDKKtor_client_coreHttpResponsePipelinePhases : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpResponsePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Parse __attribute__((swift_name("Parse")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) CSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseContainer")))
@interface CSDKKtor_client_coreHttpResponseContainer : CSDKBase
- (instancetype)initWithExpectedType:(CSDKKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("init(expectedType:response:)"))) __attribute__((objc_designated_initializer));
- (CSDKKtor_client_coreHttpResponseContainer *)doCopyExpectedType:(CSDKKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("doCopy(expectedType:response:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) CSDKKtor_utilsTypeInfo *expectedType __attribute__((swift_name("expectedType")));
@property (readonly) id response __attribute__((swift_name("response")));
@end

__attribute__((swift_name("Ktor_client_coreHttpClientCall")))
@interface CSDKKtor_client_coreHttpClientCall : CSDKBase <CSDKKotlinx_coroutines_coreCoroutineScope>
- (instancetype)initWithClient:(CSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(CSDKKtor_client_coreHttpClient *)client requestData:(CSDKKtor_client_coreHttpRequestData *)requestData responseData:(CSDKKtor_client_coreHttpResponseData *)responseData __attribute__((swift_name("init(client:requestData:responseData:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_client_coreHttpClientCallCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyInfo:(CSDKKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("body(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyNullableInfo:(CSDKKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyNullable(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)getResponseContentWithCompletionHandler:(void (^)(id<CSDKKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getResponseContent(completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL allowDoubleReceive __attribute__((swift_name("allowDoubleReceive")));
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) CSDKKtor_client_coreHttpClient *client __attribute__((swift_name("client")));
@property (readonly) id<CSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property id<CSDKKtor_client_coreHttpRequest> request __attribute__((swift_name("request")));
@property CSDKKtor_client_coreHttpResponse *response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline.Phases")))
@interface CSDKKtor_client_coreHttpSendPipelinePhases : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpSendPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Engine __attribute__((swift_name("Engine")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Monitoring __attribute__((swift_name("Monitoring")));
@property (readonly) CSDKKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) CSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol CSDKKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<CSDKKotlinKClass>)kClass provider:(id<CSDKKotlinx_serialization_coreKSerializer> (^)(NSArray<id<CSDKKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<CSDKKotlinKClass>)kClass serializer:(id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<CSDKKotlinKClass>)baseClass actualClass:(id<CSDKKotlinKClass>)actualClass actualSerializer:(id<CSDKKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<CSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<CSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<CSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<CSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<CSDKKotlinKClass>)baseClass defaultSerializerProvider:(id<CSDKKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol CSDKKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol CSDKKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol CSDKKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol CSDKKotlinKClass <CSDKKotlinKDeclarationContainer, CSDKKotlinKAnnotatedElement, CSDKKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface CSDKKotlinx_serialization_jsonJsonElementCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
- (id<CSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonClassDiscriminatorMode")))
@interface CSDKKotlinx_serialization_jsonClassDiscriminatorMode : CSDKKotlinEnum<CSDKKotlinx_serialization_jsonClassDiscriminatorMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) CSDKKotlinx_serialization_jsonClassDiscriminatorMode *none __attribute__((swift_name("none")));
@property (class, readonly) CSDKKotlinx_serialization_jsonClassDiscriminatorMode *allJsonObjects __attribute__((swift_name("allJsonObjects")));
@property (class, readonly) CSDKKotlinx_serialization_jsonClassDiscriminatorMode *polymorphic __attribute__((swift_name("polymorphic")));
+ (CSDKKotlinArray<CSDKKotlinx_serialization_jsonClassDiscriminatorMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<CSDKKotlinx_serialization_jsonClassDiscriminatorMode *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonNamingStrategy")))
@protocol CSDKKotlinx_serialization_jsonJsonNamingStrategy
@required
- (NSString *)serialNameForJsonDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor elementIndex:(int32_t)elementIndex serialName:(NSString *)serialName __attribute__((swift_name("serialNameForJson(descriptor:elementIndex:serialName:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol CSDKKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<CSDKKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<CSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol CSDKKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface CSDKKotlinx_serialization_coreSerialKind : CSDKBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol CSDKKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<CSDKKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<CSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<CSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) CSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_datetimeDateTimeFormat")))
@protocol CSDKKotlinx_datetimeDateTimeFormat
@required
- (NSString *)formatValue:(id _Nullable)value __attribute__((swift_name("format(value:)")));
- (id<CSDKKotlinAppendable>)formatToAppendable:(id<CSDKKotlinAppendable>)appendable value:(id _Nullable)value __attribute__((swift_name("formatTo(appendable:value:)")));
- (id _Nullable)parseInput:(id)input __attribute__((swift_name("parse(input:)")));
- (id _Nullable)parseOrNullInput:(id)input __attribute__((swift_name("parseOrNull(input:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl")))
@interface CSDKKtor_httpUrl : CSDKBase
@property (class, readonly, getter=companion) CSDKKtor_httpUrlCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property (readonly) NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property (readonly) NSString *encodedPath __attribute__((swift_name("encodedPath")));
@property (readonly) NSString *encodedPathAndQuery __attribute__((swift_name("encodedPathAndQuery")));
@property (readonly) NSString *encodedQuery __attribute__((swift_name("encodedQuery")));
@property (readonly) NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property (readonly) NSString *fragment __attribute__((swift_name("fragment")));
@property (readonly) NSString *host __attribute__((swift_name("host")));
@property (readonly) id<CSDKKtor_httpParameters> parameters __attribute__((swift_name("parameters")));
@property (readonly) NSString * _Nullable password __attribute__((swift_name("password")));
@property (readonly) NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@property (readonly) CSDKKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property (readonly) int32_t specifiedPort __attribute__((swift_name("specifiedPort")));
@property (readonly) BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property (readonly) NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod")))
@interface CSDKKtor_httpHttpMethod : CSDKBase
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpHttpMethodCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_httpHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Ktor_utilsStringValues")))
@protocol CSDKKtor_utilsStringValues
@required
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<CSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (void)forEachBody:(void (^)(NSString *, NSArray<NSString *> *))body __attribute__((swift_name("forEach(body:)")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_httpHeaders")))
@protocol CSDKKtor_httpHeaders <CSDKKtor_utilsStringValues>
@required
@end

__attribute__((swift_name("Ktor_httpOutgoingContent")))
@interface CSDKKtor_httpOutgoingContent : CSDKBase
- (id _Nullable)getPropertyKey:(CSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));
- (void)setPropertyKey:(CSDKKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));
- (id<CSDKKtor_httpHeaders> _Nullable)trailers __attribute__((swift_name("trailers()")));
@property (readonly) CSDKLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) CSDKKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<CSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) CSDKKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol CSDKKotlinx_coroutines_coreJob <CSDKKotlinCoroutineContextElement>
@required
- (id<CSDKKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<CSDKKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(CSDKKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (CSDKKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<CSDKKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(CSDKKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));
- (id<CSDKKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(CSDKKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<CSDKKotlinx_coroutines_coreJob>)plusOther_:(id<CSDKKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<CSDKKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<CSDKKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<CSDKKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode")))
@interface CSDKKtor_httpHttpStatusCode : CSDKBase <CSDKKotlinComparable>
- (instancetype)initWithValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("init(value:description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpHttpStatusCodeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(CSDKKtor_httpHttpStatusCode *)other __attribute__((swift_name("compareTo(other:)")));
- (CSDKKtor_httpHttpStatusCode *)doCopyValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("doCopy(value:description:)")));
- (CSDKKtor_httpHttpStatusCode *)descriptionValue:(NSString *)value __attribute__((swift_name("description(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate")))
@interface CSDKKtor_utilsGMTDate : CSDKBase <CSDKKotlinComparable>
@property (class, readonly, getter=companion) CSDKKtor_utilsGMTDateCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(CSDKKtor_utilsGMTDate *)other __attribute__((swift_name("compareTo(other:)")));
- (CSDKKtor_utilsGMTDate *)doCopySeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(CSDKKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(CSDKKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("doCopy(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth")));
@property (readonly) CSDKKtor_utilsWeekDay *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) CSDKKtor_utilsMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion")))
@interface CSDKKtor_httpHttpProtocolVersion : CSDKBase
- (instancetype)initWithName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("init(name:major:minor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpHttpProtocolVersionCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_httpHttpProtocolVersion *)doCopyName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("doCopy(name:major:minor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_ioByteReadChannel")))
@protocol CSDKKtor_ioByteReadChannel
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitContentWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("awaitContent(completionHandler:)")));
- (BOOL)cancelCause_:(CSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)discardMax:(int64_t)max completionHandler:(void (^)(CSDKLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("discard(max:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)peekToDestination:(CSDKKtor_ioMemory *)destination destinationOffset:(int64_t)destinationOffset offset:(int64_t)offset min:(int64_t)min max:(int64_t)max completionHandler:(void (^)(CSDKLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("peekTo(destination:destinationOffset:offset:min:max:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(CSDKKtor_ioChunkBuffer *)dst completionHandler:(void (^)(CSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:completionHandler:)")));
- (int32_t)readAvailableMin:(int32_t)min block:(void (^)(CSDKKtor_ioBuffer *))block __attribute__((swift_name("readAvailable(min:block:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(CSDKKotlinByteArray *)dst offset:(int32_t)offset length:(int32_t)length completionHandler:(void (^)(CSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(void *)dst offset:(int32_t)offset length:(int32_t)length completionHandler_:(void (^)(CSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAvailableDst:(void *)dst offset:(int64_t)offset length:(int64_t)length completionHandler__:(void (^)(CSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readAvailable(dst:offset:length:completionHandler__:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readBooleanWithCompletionHandler:(void (^)(CSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readBoolean(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readByteWithCompletionHandler:(void (^)(CSDKByte * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readByte(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readDoubleWithCompletionHandler:(void (^)(CSDKDouble * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readDouble(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFloatWithCompletionHandler:(void (^)(CSDKFloat * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readFloat(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(CSDKKtor_ioChunkBuffer *)dst n:(int32_t)n completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:n:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(CSDKKotlinByteArray *)dst offset:(int32_t)offset length:(int32_t)length completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(void *)dst offset:(int32_t)offset length:(int32_t)length completionHandler_:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readFullyDst:(void *)dst offset:(int64_t)offset length:(int64_t)length completionHandler__:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readFully(dst:offset:length:completionHandler__:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readIntWithCompletionHandler:(void (^)(CSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readInt(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readLongWithCompletionHandler:(void (^)(CSDKLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readLong(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readPacketSize:(int32_t)size completionHandler:(void (^)(CSDKKtor_ioByteReadPacket * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readPacket(size:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readRemainingLimit:(int64_t)limit completionHandler:(void (^)(CSDKKtor_ioByteReadPacket * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readRemaining(limit:completionHandler:)")));
- (void)readSessionConsumer:(void (^)(id<CSDKKtor_ioReadSession>))consumer __attribute__((swift_name("readSession(consumer:)"))) __attribute__((deprecated("Use read { } instead.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readShortWithCompletionHandler:(void (^)(CSDKShort * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readShort(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readSuspendableSessionConsumer:(id<CSDKKotlinSuspendFunction1>)consumer completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("readSuspendableSession(consumer:completionHandler:)"))) __attribute__((deprecated("Use read { } instead.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readUTF8LineLimit:(int32_t)limit completionHandler:(void (^)(NSString * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("readUTF8Line(limit:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readUTF8LineToOut:(id<CSDKKotlinAppendable>)out limit:(int32_t)limit completionHandler:(void (^)(CSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readUTF8LineTo(out:limit:completionHandler:)")));
@property (readonly) int32_t availableForRead __attribute__((swift_name("availableForRead")));
@property (readonly) CSDKKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForRead __attribute__((swift_name("isClosedForRead")));
@property (readonly) BOOL isClosedForWrite __attribute__((swift_name("isClosedForWrite")));
@property (readonly) int64_t totalBytesRead __attribute__((swift_name("totalBytesRead")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilder")))
@protocol CSDKKtor_utilsStringValuesBuilder
@required
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<CSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<CSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<CSDKKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<CSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilderImpl")))
@interface CSDKKtor_utilsStringValuesBuilderImpl : CSDKBase <CSDKKtor_utilsStringValuesBuilder>
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer));
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<CSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<CSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<CSDKKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<CSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) CSDKMutableDictionary<NSString *, NSMutableArray<NSString *> *> *values __attribute__((swift_name("values")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeadersBuilder")))
@interface CSDKKtor_httpHeadersBuilder : CSDKKtor_utilsStringValuesBuilderImpl
- (instancetype)initWithSize:(int32_t)size __attribute__((swift_name("init(size:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<CSDKKtor_httpHeaders>)build __attribute__((swift_name("build()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder.Companion")))
@interface CSDKKtor_client_coreHttpRequestBuilderCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpRequestBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder")))
@interface CSDKKtor_httpURLBuilder : CSDKBase
- (instancetype)initWithProtocol:(CSDKKtor_httpURLProtocol *)protocol host:(NSString *)host port:(int32_t)port user:(NSString * _Nullable)user password:(NSString * _Nullable)password pathSegments:(NSArray<NSString *> *)pathSegments parameters:(id<CSDKKtor_httpParameters>)parameters fragment:(NSString *)fragment trailingQuery:(BOOL)trailingQuery __attribute__((swift_name("init(protocol:host:port:user:password:pathSegments:parameters:fragment:trailingQuery:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpURLBuilderCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_httpUrl *)build __attribute__((swift_name("build()")));
- (NSString *)buildString __attribute__((swift_name("buildString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property id<CSDKKtor_httpParametersBuilder> encodedParameters __attribute__((swift_name("encodedParameters")));
@property NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property NSArray<NSString *> *encodedPathSegments __attribute__((swift_name("encodedPathSegments")));
@property NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property NSString *fragment __attribute__((swift_name("fragment")));
@property NSString *host __attribute__((swift_name("host")));
@property (readonly) id<CSDKKtor_httpParametersBuilder> parameters __attribute__((swift_name("parameters")));
@property NSString * _Nullable password __attribute__((swift_name("password")));
@property NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property int32_t port __attribute__((swift_name("port")));
@property CSDKKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsTypeInfo")))
@interface CSDKKtor_utilsTypeInfo : CSDKBase
- (instancetype)initWithType:(id<CSDKKotlinKClass>)type reifiedType:(id<CSDKKotlinKType>)reifiedType kotlinType:(id<CSDKKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:reifiedType:kotlinType:)"))) __attribute__((objc_designated_initializer));
- (CSDKKtor_utilsTypeInfo *)doCopyType:(id<CSDKKotlinKClass>)type reifiedType:(id<CSDKKotlinKType>)reifiedType kotlinType:(id<CSDKKotlinKType> _Nullable)kotlinType __attribute__((swift_name("doCopy(type:reifiedType:kotlinType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<CSDKKotlinKType> _Nullable kotlinType __attribute__((swift_name("kotlinType")));
@property (readonly) id<CSDKKotlinKType> reifiedType __attribute__((swift_name("reifiedType")));
@property (readonly) id<CSDKKotlinKClass> type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientCall.Companion")))
@interface CSDKKtor_client_coreHttpClientCallCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_client_coreHttpClientCallCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsAttributeKey<id> *CustomResponse __attribute__((swift_name("CustomResponse"))) __attribute__((unavailable("This is going to be removed. Please file a ticket with clarification why and what for do you need it.")));
@end

__attribute__((swift_name("Ktor_client_coreHttpRequest")))
@protocol CSDKKtor_client_coreHttpRequest <CSDKKtor_httpHttpMessage, CSDKKotlinx_coroutines_coreCoroutineScope>
@required
@property (readonly) id<CSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) CSDKKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) CSDKKtor_httpOutgoingContent *content __attribute__((swift_name("content")));
@property (readonly) CSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) CSDKKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol CSDKKotlinAppendable
@required
- (id<CSDKKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (id<CSDKKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (id<CSDKKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl.Companion")))
@interface CSDKKtor_httpUrlCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpUrlCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Ktor_httpParameters")))
@protocol CSDKKtor_httpParameters <CSDKKtor_utilsStringValues>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol")))
@interface CSDKKtor_httpURLProtocol : CSDKBase
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpURLProtocolCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_httpURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t defaultPort __attribute__((swift_name("defaultPort")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod.Companion")))
@interface CSDKKtor_httpHttpMethodCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpHttpMethodCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_httpHttpMethod *)parseMethod:(NSString *)method __attribute__((swift_name("parse(method:)")));
@property (readonly) NSArray<CSDKKtor_httpHttpMethod *> *DefaultMethods __attribute__((swift_name("DefaultMethods")));
@property (readonly) CSDKKtor_httpHttpMethod *Delete __attribute__((swift_name("Delete")));
@property (readonly) CSDKKtor_httpHttpMethod *Get __attribute__((swift_name("Get")));
@property (readonly) CSDKKtor_httpHttpMethod *Head __attribute__((swift_name("Head")));
@property (readonly) CSDKKtor_httpHttpMethod *Options __attribute__((swift_name("Options")));
@property (readonly) CSDKKtor_httpHttpMethod *Patch __attribute__((swift_name("Patch")));
@property (readonly) CSDKKtor_httpHttpMethod *Post __attribute__((swift_name("Post")));
@property (readonly) CSDKKtor_httpHttpMethod *Put __attribute__((swift_name("Put")));
@end

__attribute__((swift_name("KotlinMapEntry")))
@protocol CSDKKotlinMapEntry
@required
@property (readonly) id _Nullable key __attribute__((swift_name("key")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("Ktor_httpHeaderValueWithParameters")))
@interface CSDKKtor_httpHeaderValueWithParameters : CSDKBase
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<CSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_httpHeaderValueWithParametersCompanion *companion __attribute__((swift_name("companion")));
- (NSString * _Nullable)parameterName:(NSString *)name __attribute__((swift_name("parameter(name:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) NSArray<CSDKKtor_httpHeaderValueParam *> *parameters __attribute__((swift_name("parameters")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType")))
@interface CSDKKtor_httpContentType : CSDKKtor_httpHeaderValueWithParameters
- (instancetype)initWithContentType:(NSString *)contentType contentSubtype:(NSString *)contentSubtype parameters:(NSArray<CSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(contentType:contentSubtype:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<CSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_httpContentTypeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)matchPattern:(CSDKKtor_httpContentType *)pattern __attribute__((swift_name("match(pattern:)")));
- (BOOL)matchPattern_:(NSString *)pattern __attribute__((swift_name("match(pattern_:)")));
- (CSDKKtor_httpContentType *)withParameterName:(NSString *)name value:(NSString *)value __attribute__((swift_name("withParameter(name:value:)")));
- (CSDKKtor_httpContentType *)withoutParameters __attribute__((swift_name("withoutParameters()")));
@property (readonly) NSString *contentSubtype __attribute__((swift_name("contentSubtype")));
@property (readonly) NSString *contentType __attribute__((swift_name("contentType")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol CSDKKotlinx_coroutines_coreChildHandle <CSDKKotlinx_coroutines_coreDisposableHandle>
@required
- (BOOL)childCancelledCause:(CSDKKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));
@property (readonly) id<CSDKKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol CSDKKotlinx_coroutines_coreChildJob <CSDKKotlinx_coroutines_coreJob>
@required
- (void)parentCancelledParentJob:(id<CSDKKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol CSDKKotlinSequence
@required
- (id<CSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol CSDKKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) CSDKKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<CSDKKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(CSDKKotlinThrowable *) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<CSDKKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol CSDKKotlinx_coroutines_coreSelectClause0 <CSDKKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode.Companion")))
@interface CSDKKtor_httpHttpStatusCodeCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpHttpStatusCodeCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_httpHttpStatusCode *)fromValueValue:(int32_t)value __attribute__((swift_name("fromValue(value:)")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Accepted __attribute__((swift_name("Accepted")));
@property (readonly) CSDKKtor_httpHttpStatusCode *BadGateway __attribute__((swift_name("BadGateway")));
@property (readonly) CSDKKtor_httpHttpStatusCode *BadRequest __attribute__((swift_name("BadRequest")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Conflict __attribute__((swift_name("Conflict")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Continue __attribute__((swift_name("Continue")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Created __attribute__((swift_name("Created")));
@property (readonly) CSDKKtor_httpHttpStatusCode *ExpectationFailed __attribute__((swift_name("ExpectationFailed")));
@property (readonly) CSDKKtor_httpHttpStatusCode *FailedDependency __attribute__((swift_name("FailedDependency")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Forbidden __attribute__((swift_name("Forbidden")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Found __attribute__((swift_name("Found")));
@property (readonly) CSDKKtor_httpHttpStatusCode *GatewayTimeout __attribute__((swift_name("GatewayTimeout")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Gone __attribute__((swift_name("Gone")));
@property (readonly) CSDKKtor_httpHttpStatusCode *InsufficientStorage __attribute__((swift_name("InsufficientStorage")));
@property (readonly) CSDKKtor_httpHttpStatusCode *InternalServerError __attribute__((swift_name("InternalServerError")));
@property (readonly) CSDKKtor_httpHttpStatusCode *LengthRequired __attribute__((swift_name("LengthRequired")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Locked __attribute__((swift_name("Locked")));
@property (readonly) CSDKKtor_httpHttpStatusCode *MethodNotAllowed __attribute__((swift_name("MethodNotAllowed")));
@property (readonly) CSDKKtor_httpHttpStatusCode *MovedPermanently __attribute__((swift_name("MovedPermanently")));
@property (readonly) CSDKKtor_httpHttpStatusCode *MultiStatus __attribute__((swift_name("MultiStatus")));
@property (readonly) CSDKKtor_httpHttpStatusCode *MultipleChoices __attribute__((swift_name("MultipleChoices")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NoContent __attribute__((swift_name("NoContent")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NonAuthoritativeInformation __attribute__((swift_name("NonAuthoritativeInformation")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NotAcceptable __attribute__((swift_name("NotAcceptable")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NotFound __attribute__((swift_name("NotFound")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NotImplemented __attribute__((swift_name("NotImplemented")));
@property (readonly) CSDKKtor_httpHttpStatusCode *NotModified __attribute__((swift_name("NotModified")));
@property (readonly) CSDKKtor_httpHttpStatusCode *OK __attribute__((swift_name("OK")));
@property (readonly) CSDKKtor_httpHttpStatusCode *PartialContent __attribute__((swift_name("PartialContent")));
@property (readonly) CSDKKtor_httpHttpStatusCode *PayloadTooLarge __attribute__((swift_name("PayloadTooLarge")));
@property (readonly) CSDKKtor_httpHttpStatusCode *PaymentRequired __attribute__((swift_name("PaymentRequired")));
@property (readonly) CSDKKtor_httpHttpStatusCode *PermanentRedirect __attribute__((swift_name("PermanentRedirect")));
@property (readonly) CSDKKtor_httpHttpStatusCode *PreconditionFailed __attribute__((swift_name("PreconditionFailed")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Processing __attribute__((swift_name("Processing")));
@property (readonly) CSDKKtor_httpHttpStatusCode *ProxyAuthenticationRequired __attribute__((swift_name("ProxyAuthenticationRequired")));
@property (readonly) CSDKKtor_httpHttpStatusCode *RequestHeaderFieldTooLarge __attribute__((swift_name("RequestHeaderFieldTooLarge")));
@property (readonly) CSDKKtor_httpHttpStatusCode *RequestTimeout __attribute__((swift_name("RequestTimeout")));
@property (readonly) CSDKKtor_httpHttpStatusCode *RequestURITooLong __attribute__((swift_name("RequestURITooLong")));
@property (readonly) CSDKKtor_httpHttpStatusCode *RequestedRangeNotSatisfiable __attribute__((swift_name("RequestedRangeNotSatisfiable")));
@property (readonly) CSDKKtor_httpHttpStatusCode *ResetContent __attribute__((swift_name("ResetContent")));
@property (readonly) CSDKKtor_httpHttpStatusCode *SeeOther __attribute__((swift_name("SeeOther")));
@property (readonly) CSDKKtor_httpHttpStatusCode *ServiceUnavailable __attribute__((swift_name("ServiceUnavailable")));
@property (readonly) CSDKKtor_httpHttpStatusCode *SwitchProxy __attribute__((swift_name("SwitchProxy")));
@property (readonly) CSDKKtor_httpHttpStatusCode *SwitchingProtocols __attribute__((swift_name("SwitchingProtocols")));
@property (readonly) CSDKKtor_httpHttpStatusCode *TemporaryRedirect __attribute__((swift_name("TemporaryRedirect")));
@property (readonly) CSDKKtor_httpHttpStatusCode *TooEarly __attribute__((swift_name("TooEarly")));
@property (readonly) CSDKKtor_httpHttpStatusCode *TooManyRequests __attribute__((swift_name("TooManyRequests")));
@property (readonly) CSDKKtor_httpHttpStatusCode *Unauthorized __attribute__((swift_name("Unauthorized")));
@property (readonly) CSDKKtor_httpHttpStatusCode *UnprocessableEntity __attribute__((swift_name("UnprocessableEntity")));
@property (readonly) CSDKKtor_httpHttpStatusCode *UnsupportedMediaType __attribute__((swift_name("UnsupportedMediaType")));
@property (readonly) CSDKKtor_httpHttpStatusCode *UpgradeRequired __attribute__((swift_name("UpgradeRequired")));
@property (readonly) CSDKKtor_httpHttpStatusCode *UseProxy __attribute__((swift_name("UseProxy")));
@property (readonly) CSDKKtor_httpHttpStatusCode *VariantAlsoNegotiates __attribute__((swift_name("VariantAlsoNegotiates")));
@property (readonly) CSDKKtor_httpHttpStatusCode *VersionNotSupported __attribute__((swift_name("VersionNotSupported")));
@property (readonly) NSArray<CSDKKtor_httpHttpStatusCode *> *allStatusCodes __attribute__((swift_name("allStatusCodes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate.Companion")))
@interface CSDKKtor_utilsGMTDateCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_utilsGMTDateCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_utilsGMTDate *START __attribute__((swift_name("START")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay")))
@interface CSDKKtor_utilsWeekDay : CSDKKotlinEnum<CSDKKtor_utilsWeekDay *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_utilsWeekDayCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) CSDKKtor_utilsWeekDay *monday __attribute__((swift_name("monday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *friday __attribute__((swift_name("friday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) CSDKKtor_utilsWeekDay *sunday __attribute__((swift_name("sunday")));
+ (CSDKKotlinArray<CSDKKtor_utilsWeekDay *> *)values __attribute__((swift_name("values()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth")))
@interface CSDKKtor_utilsMonth : CSDKKotlinEnum<CSDKKtor_utilsMonth *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_utilsMonthCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) CSDKKtor_utilsMonth *january __attribute__((swift_name("january")));
@property (class, readonly) CSDKKtor_utilsMonth *february __attribute__((swift_name("february")));
@property (class, readonly) CSDKKtor_utilsMonth *march __attribute__((swift_name("march")));
@property (class, readonly) CSDKKtor_utilsMonth *april __attribute__((swift_name("april")));
@property (class, readonly) CSDKKtor_utilsMonth *may __attribute__((swift_name("may")));
@property (class, readonly) CSDKKtor_utilsMonth *june __attribute__((swift_name("june")));
@property (class, readonly) CSDKKtor_utilsMonth *july __attribute__((swift_name("july")));
@property (class, readonly) CSDKKtor_utilsMonth *august __attribute__((swift_name("august")));
@property (class, readonly) CSDKKtor_utilsMonth *september __attribute__((swift_name("september")));
@property (class, readonly) CSDKKtor_utilsMonth *october __attribute__((swift_name("october")));
@property (class, readonly) CSDKKtor_utilsMonth *november __attribute__((swift_name("november")));
@property (class, readonly) CSDKKtor_utilsMonth *december __attribute__((swift_name("december")));
+ (CSDKKotlinArray<CSDKKtor_utilsMonth *> *)values __attribute__((swift_name("values()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion.Companion")))
@interface CSDKKtor_httpHttpProtocolVersionCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpHttpProtocolVersionCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_httpHttpProtocolVersion *)fromValueName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("fromValue(name:major:minor:)")));
- (CSDKKtor_httpHttpProtocolVersion *)parseValue:(id)value __attribute__((swift_name("parse(value:)")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *HTTP_1_0 __attribute__((swift_name("HTTP_1_0")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *HTTP_1_1 __attribute__((swift_name("HTTP_1_1")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *HTTP_2_0 __attribute__((swift_name("HTTP_2_0")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *QUIC __attribute__((swift_name("QUIC")));
@property (readonly) CSDKKtor_httpHttpProtocolVersion *SPDY_3 __attribute__((swift_name("SPDY_3")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioMemory")))
@interface CSDKKtor_ioMemory : CSDKBase
- (instancetype)initWithPointer:(void *)pointer size:(int64_t)size __attribute__((swift_name("init(pointer:size:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKtor_ioMemoryCompanion *companion __attribute__((swift_name("companion")));
- (void)doCopyToDestination:(CSDKKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length destinationOffset:(int32_t)destinationOffset __attribute__((swift_name("doCopyTo(destination:offset:length:destinationOffset:)")));
- (void)doCopyToDestination:(CSDKKtor_ioMemory *)destination offset:(int64_t)offset length:(int64_t)length destinationOffset_:(int64_t)destinationOffset __attribute__((swift_name("doCopyTo(destination:offset:length:destinationOffset_:)")));
- (int8_t)loadAtIndex:(int32_t)index __attribute__((swift_name("loadAt(index:)")));
- (int8_t)loadAtIndex_:(int64_t)index __attribute__((swift_name("loadAt(index_:)")));
- (CSDKKtor_ioMemory *)sliceOffset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("slice(offset:length:)")));
- (CSDKKtor_ioMemory *)sliceOffset:(int64_t)offset length_:(int64_t)length __attribute__((swift_name("slice(offset:length_:)")));
- (void)storeAtIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("storeAt(index:value:)")));
- (void)storeAtIndex:(int64_t)index value_:(int8_t)value __attribute__((swift_name("storeAt(index:value_:)")));
@property (readonly) void *pointer __attribute__((swift_name("pointer")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
@property (readonly) int32_t size32 __attribute__((swift_name("size32")));
@end

__attribute__((swift_name("Ktor_ioBuffer")))
@interface CSDKKtor_ioBuffer : CSDKBase
- (instancetype)initWithMemory:(CSDKKtor_ioMemory *)memory __attribute__((swift_name("init(memory:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
@property (class, readonly, getter=companion) CSDKKtor_ioBufferCompanion *companion __attribute__((swift_name("companion")));
- (void)commitWrittenCount:(int32_t)count __attribute__((swift_name("commitWritten(count:)")));
- (void)discardExactCount:(int32_t)count __attribute__((swift_name("discardExact(count:)")));
- (CSDKKtor_ioBuffer *)duplicate __attribute__((swift_name("duplicate()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)duplicateToCopy:(CSDKKtor_ioBuffer *)copy __attribute__((swift_name("duplicateTo(copy:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (void)reserveEndGapEndGap:(int32_t)endGap __attribute__((swift_name("reserveEndGap(endGap:)")));
- (void)reserveStartGapStartGap:(int32_t)startGap __attribute__((swift_name("reserveStartGap(startGap:)")));
- (void)reset __attribute__((swift_name("reset()")));
- (void)resetForRead __attribute__((swift_name("resetForRead()")));
- (void)resetForWrite __attribute__((swift_name("resetForWrite()")));
- (void)resetForWriteLimit:(int32_t)limit __attribute__((swift_name("resetForWrite(limit:)")));
- (void)rewindCount:(int32_t)count __attribute__((swift_name("rewind(count:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (int32_t)tryPeekByte __attribute__((swift_name("tryPeekByte()")));
- (int32_t)tryReadByte __attribute__((swift_name("tryReadByte()")));
- (void)writeByteValue:(int8_t)value __attribute__((swift_name("writeByte(value:)")));
@property (readonly) int32_t capacity __attribute__((swift_name("capacity")));
@property (readonly) int32_t endGap __attribute__((swift_name("endGap")));
@property (readonly) int32_t limit __attribute__((swift_name("limit")));
@property (readonly) CSDKKtor_ioMemory *memory __attribute__((swift_name("memory")));
@property (readonly) int32_t readPosition __attribute__((swift_name("readPosition")));
@property (readonly) int32_t readRemaining __attribute__((swift_name("readRemaining")));
@property (readonly) int32_t startGap __attribute__((swift_name("startGap")));
@property (readonly) int32_t writePosition __attribute__((swift_name("writePosition")));
@property (readonly) int32_t writeRemaining __attribute__((swift_name("writeRemaining")));
@end

__attribute__((swift_name("Ktor_ioChunkBuffer")))
@interface CSDKKtor_ioChunkBuffer : CSDKKtor_ioBuffer
- (instancetype)initWithMemory:(CSDKKtor_ioMemory *)memory origin:(CSDKKtor_ioChunkBuffer * _Nullable)origin parentPool:(id<CSDKKtor_ioObjectPool> _Nullable)parentPool __attribute__((swift_name("init(memory:origin:parentPool:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
- (instancetype)initWithMemory:(CSDKKtor_ioMemory *)memory __attribute__((swift_name("init(memory:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_ioChunkBufferCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKtor_ioChunkBuffer * _Nullable)cleanNext __attribute__((swift_name("cleanNext()")));
- (CSDKKtor_ioChunkBuffer *)duplicate __attribute__((swift_name("duplicate()")));
- (void)releasePool:(id<CSDKKtor_ioObjectPool>)pool __attribute__((swift_name("release(pool:)")));
- (void)reset __attribute__((swift_name("reset()")));
@property (getter=next_) CSDKKtor_ioChunkBuffer * _Nullable next __attribute__((swift_name("next")));
@property (readonly) CSDKKtor_ioChunkBuffer * _Nullable origin __attribute__((swift_name("origin")));
@property (readonly) int32_t referenceCount __attribute__((swift_name("referenceCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface CSDKKotlinByteArray : CSDKBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(CSDKByte *(^)(CSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (CSDKKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Ktor_ioInput")))
@interface CSDKKtor_ioInput : CSDKBase <CSDKKtor_ioCloseable>
- (instancetype)initWithHead:(CSDKKtor_ioChunkBuffer *)head remaining:(int64_t)remaining pool:(id<CSDKKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:remaining:pool:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("\n    We're migrating to the new kotlinx-io library.\n    This declaration is deprecated and will be removed in Ktor 4.0.0\n    If you have any problems with migration, please contact us in \n    https://youtrack.jetbrains.com/issue/KTOR-6030/Migrate-to-new-kotlinx.io-library\n    ")));
@property (class, readonly, getter=companion) CSDKKtor_ioInputCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)canRead __attribute__((swift_name("canRead()")));
- (void)close __attribute__((swift_name("close()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)closeSource __attribute__((swift_name("closeSource()")));
- (int32_t)discardN:(int32_t)n __attribute__((swift_name("discard(n:)")));
- (int64_t)discardN_:(int64_t)n __attribute__((swift_name("discard(n_:)")));
- (void)discardExactN:(int32_t)n __attribute__((swift_name("discardExact(n:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (CSDKKtor_ioChunkBuffer * _Nullable)fill __attribute__((swift_name("fill()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int32_t)fillDestination:(CSDKKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("fill(destination:offset:length:)")));
- (BOOL)hasBytesN:(int32_t)n __attribute__((swift_name("hasBytes(n:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)markNoMoreChunksAvailable __attribute__((swift_name("markNoMoreChunksAvailable()")));
- (int32_t)peekToBuffer:(CSDKKtor_ioChunkBuffer *)buffer __attribute__((swift_name("peekTo(buffer:)")));
- (int64_t)peekToDestination:(CSDKKtor_ioMemory *)destination destinationOffset:(int64_t)destinationOffset offset:(int64_t)offset min:(int64_t)min max:(int64_t)max __attribute__((swift_name("peekTo(destination:destinationOffset:offset:min:max:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (NSString *)readTextMin:(int32_t)min max:(int32_t)max __attribute__((swift_name("readText(min:max:)")));
- (int32_t)readTextOut:(id<CSDKKotlinAppendable>)out min:(int32_t)min max:(int32_t)max __attribute__((swift_name("readText(out:min:max:)")));
- (NSString *)readTextExactExactCharacters:(int32_t)exactCharacters __attribute__((swift_name("readTextExact(exactCharacters:)")));
- (void)readTextExactOut:(id<CSDKKotlinAppendable>)out exactCharacters:(int32_t)exactCharacters __attribute__((swift_name("readTextExact(out:exactCharacters:)")));
- (void)release_ __attribute__((swift_name("release()")));
- (int32_t)tryPeek __attribute__((swift_name("tryPeek()")));
@property (readonly) BOOL endOfInput __attribute__((swift_name("endOfInput")));
@property (readonly) id<CSDKKtor_ioObjectPool> pool __attribute__((swift_name("pool")));
@property (readonly) int64_t remaining __attribute__((swift_name("remaining")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioByteReadPacket")))
@interface CSDKKtor_ioByteReadPacket : CSDKKtor_ioInput
- (instancetype)initWithHead:(CSDKKtor_ioChunkBuffer *)head pool:(id<CSDKKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:pool:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithHead:(CSDKKtor_ioChunkBuffer *)head remaining:(int64_t)remaining pool:(id<CSDKKtor_ioObjectPool>)pool __attribute__((swift_name("init(head:remaining:pool:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) CSDKKtor_ioByteReadPacketCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)closeSource __attribute__((swift_name("closeSource()")));
- (CSDKKtor_ioByteReadPacket *)doCopy __attribute__((swift_name("doCopy()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (CSDKKtor_ioChunkBuffer * _Nullable)fill __attribute__((swift_name("fill()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (int32_t)fillDestination:(CSDKKtor_ioMemory *)destination offset:(int32_t)offset length:(int32_t)length __attribute__((swift_name("fill(destination:offset:length:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Ktor_ioReadSession")))
@protocol CSDKKtor_ioReadSession
@required
- (int32_t)discardN:(int32_t)n __attribute__((swift_name("discard(n:)")));
- (CSDKKtor_ioChunkBuffer * _Nullable)requestAtLeast:(int32_t)atLeast __attribute__((swift_name("request(atLeast:)")));
@property (readonly) int32_t availableForRead __attribute__((swift_name("availableForRead")));
@end

__attribute__((swift_name("KotlinSuspendFunction1")))
@protocol CSDKKotlinSuspendFunction1 <CSDKKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder.Companion")))
@interface CSDKKtor_httpURLBuilderCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpURLBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Ktor_httpParametersBuilder")))
@protocol CSDKKtor_httpParametersBuilder <CSDKKtor_utilsStringValuesBuilder>
@required
@end

__attribute__((swift_name("KotlinKType")))
@protocol CSDKKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<CSDKKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<CSDKKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol.Companion")))
@interface CSDKKtor_httpURLProtocolCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpURLProtocolCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_httpURLProtocol *)createOrDefaultName:(NSString *)name __attribute__((swift_name("createOrDefault(name:)")));
@property (readonly) CSDKKtor_httpURLProtocol *HTTP __attribute__((swift_name("HTTP")));
@property (readonly) CSDKKtor_httpURLProtocol *HTTPS __attribute__((swift_name("HTTPS")));
@property (readonly) CSDKKtor_httpURLProtocol *SOCKS __attribute__((swift_name("SOCKS")));
@property (readonly) CSDKKtor_httpURLProtocol *WS __attribute__((swift_name("WS")));
@property (readonly) CSDKKtor_httpURLProtocol *WSS __attribute__((swift_name("WSS")));
@property (readonly) NSDictionary<NSString *, CSDKKtor_httpURLProtocol *> *byName __attribute__((swift_name("byName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueParam")))
@interface CSDKKtor_httpHeaderValueParam : CSDKBase
- (instancetype)initWithName:(NSString *)name value:(NSString *)value __attribute__((swift_name("init(name:value:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("init(name:value:escapeValue:)"))) __attribute__((objc_designated_initializer));
- (CSDKKtor_httpHeaderValueParam *)doCopyName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("doCopy(name:value:escapeValue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL escapeValue __attribute__((swift_name("escapeValue")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters.Companion")))
@interface CSDKKtor_httpHeaderValueWithParametersCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpHeaderValueWithParametersCompanion *shared __attribute__((swift_name("shared")));
- (id _Nullable)parseValue:(NSString *)value init:(id _Nullable (^)(NSString *, NSArray<CSDKKtor_httpHeaderValueParam *> *))init __attribute__((swift_name("parse(value:init:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType.Companion")))
@interface CSDKKtor_httpContentTypeCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_httpContentTypeCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_httpContentType *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));
@property (readonly) CSDKKtor_httpContentType *Any __attribute__((swift_name("Any")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol CSDKKotlinx_coroutines_coreParentJob <CSDKKotlinx_coroutines_coreJob>
@required
- (CSDKKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol CSDKKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<CSDKKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<CSDKKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay.Companion")))
@interface CSDKKtor_utilsWeekDayCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_utilsWeekDayCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_utilsWeekDay *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (CSDKKtor_utilsWeekDay *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth.Companion")))
@interface CSDKKtor_utilsMonthCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_utilsMonthCompanion *shared __attribute__((swift_name("shared")));
- (CSDKKtor_utilsMonth *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (CSDKKtor_utilsMonth *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioMemory.Companion")))
@interface CSDKKtor_ioMemoryCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_ioMemoryCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_ioMemory *Empty __attribute__((swift_name("Empty")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioBuffer.Companion")))
@interface CSDKKtor_ioBufferCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_ioBufferCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_ioBuffer *Empty __attribute__((swift_name("Empty")));
@property (readonly) int32_t ReservedSize __attribute__((swift_name("ReservedSize")));
@end

__attribute__((swift_name("Ktor_ioObjectPool")))
@protocol CSDKKtor_ioObjectPool <CSDKKtor_ioCloseable>
@required
- (id)borrow __attribute__((swift_name("borrow()")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (void)recycleInstance:(id)instance __attribute__((swift_name("recycle(instance:)")));
@property (readonly) int32_t capacity __attribute__((swift_name("capacity")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioChunkBuffer.Companion")))
@interface CSDKKtor_ioChunkBufferCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_ioChunkBufferCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_ioChunkBuffer *Empty __attribute__((swift_name("Empty")));
@property (readonly) id<CSDKKtor_ioObjectPool> EmptyPool __attribute__((swift_name("EmptyPool")));
@property (readonly) id<CSDKKtor_ioObjectPool> Pool __attribute__((swift_name("Pool")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface CSDKKotlinByteIterator : CSDKBase <CSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (CSDKByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioInput.Companion")))
@interface CSDKKtor_ioInputCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_ioInputCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioByteReadPacket.Companion")))
@interface CSDKKtor_ioByteReadPacketCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKtor_ioByteReadPacketCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) CSDKKtor_ioByteReadPacket *Empty __attribute__((swift_name("Empty")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface CSDKKotlinKTypeProjection : CSDKBase
- (instancetype)initWithVariance:(CSDKKotlinKVariance * _Nullable)variance type:(id<CSDKKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) CSDKKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
- (CSDKKotlinKTypeProjection *)doCopyVariance:(CSDKKotlinKVariance * _Nullable)variance type:(id<CSDKKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<CSDKKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) CSDKKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface CSDKKotlinKVariance : CSDKKotlinEnum<CSDKKotlinKVariance *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) CSDKKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) CSDKKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) CSDKKotlinKVariance *out __attribute__((swift_name("out")));
+ (CSDKKotlinArray<CSDKKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<CSDKKotlinKVariance *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface CSDKKotlinKTypeProjectionCompanion : CSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) CSDKKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (CSDKKotlinKTypeProjection *)contravariantType:(id<CSDKKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (CSDKKotlinKTypeProjection *)covariantType:(id<CSDKKotlinKType>)type __attribute__((swift_name("covariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (CSDKKotlinKTypeProjection *)invariantType:(id<CSDKKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@property (readonly) CSDKKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
