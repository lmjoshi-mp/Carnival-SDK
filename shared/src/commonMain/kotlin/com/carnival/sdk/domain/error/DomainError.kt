package com.carnival.sdk.domain.error

sealed class DomainError(
    open val message: String,
    open val cause: Throwable? = null,
) {
    data class NetworkError(
        override val message: String,
        override val cause: Throwable? = null,
    ) : DomainError(message, cause)

    data class CacheError(
        override val message: String,
        override val cause: Throwable? = null,
    ) : DomainError(message, cause)

    data class SyncError(
        override val message: String,
        override val cause: Throwable? = null,
    ) : DomainError(message, cause)

    data class UnauthorizedError(
        override val message: String = "Unauthorized request",
        override val cause: Throwable? = null,
    ) : DomainError(message, cause)
}
