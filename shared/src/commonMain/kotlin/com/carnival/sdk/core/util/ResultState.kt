package com.carnival.sdk.core.util

import com.carnival.sdk.domain.error.DomainError

sealed class ResultState<out T> {
    data object Loading : ResultState<Nothing>()
    data class Success<T>(val data: T) : ResultState<T>()
    data class Error(val error: DomainError) : ResultState<Nothing>()
}
