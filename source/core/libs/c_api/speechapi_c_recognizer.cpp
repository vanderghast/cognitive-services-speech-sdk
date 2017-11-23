#include "stdafx.h"


using namespace CARBON_IMPL_NAMESPACE();


SPXAPI_(bool) Recognzier_Handle_IsValid(SPXRECOHANDLE hreco)
{
    bool fIsValid = false;
    
    try
    {
        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        fIsValid = recohandles->IsTracked(hreco);
    }
    catch (SPXHR hr)
    {
        SPX_REPORT_ON_FAIL(hr);
        return false;
    }
    catch (std::exception ex)
    {
        SPX_REPORT_ON_FAIL(SPXERR_UNHANDLED_EXCEPTION);
        return false;
    }

    return fIsValid;
}

SPXAPI Recognizer_Handle_Close(SPXRECOHANDLE hreco)
{
    SPX_INIT_HR(hr);

    try
    {
        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        recohandles->StopTracking(hreco);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI_(bool) Recognizer_AsyncHandle_IsValid(SPXASYNCHANDLE hasync)
{
    bool fIsValid = false;

    try
    {
        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        fIsValid = asynchandles->IsTracked(hasync);
    }
    catch (SPXHR hr)
    {
        SPX_REPORT_ON_FAIL(hr);
        return false;
    }
    catch (std::exception ex)
    {
        SPX_REPORT_ON_FAIL(SPXERR_UNHANDLED_EXCEPTION);
        return false;
    }

    return fIsValid;
}

SPXAPI Recognizer_AsyncHandle_Close(SPXASYNCHANDLE hasync)
{
    SPX_INIT_HR(hr);

    try
    {
        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        asynchandles->StopTracking(hasync);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI_(bool) Recognizer_ResultHandle_IsValid(SPXRESULTHANDLE hresult)
{
    bool fIsValid = false;

    try
    {
        auto resulthandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognitionResult, SPXRESULTHANDLE>();
        fIsValid = resulthandles->IsTracked(hresult);
    }
    catch (SPXHR hr)
    {
        SPX_REPORT_ON_FAIL(hr);
        return false;
    }
    catch (std::exception ex)
    {
        SPX_REPORT_ON_FAIL(SPXERR_UNHANDLED_EXCEPTION);
        return false;
    }

    return fIsValid;
}

SPXAPI Recognizer_ResultHandle_Close(SPXRESULTHANDLE hresult)
{
    SPX_INIT_HR(hr);

    try
    {
        auto resulthandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognitionResult, SPXRESULTHANDLE>();
        resulthandles->StopTracking(hresult);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI_(bool) Recognizer_EventHandle_IsValid(SPXEVENTHANDLE hevent)
{
    return false; // TODO: RobCh: SPXERR_NOT_IMPL
}

SPXAPI Recognizer_EventHandle_Close(SPXEVENTHANDLE hevent)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_Enable(SPXRECOHANDLE hreco)
{
    SPX_INIT_HR(hr);
    
    try
    {
        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];
        precognizer->Enable();
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_Disable(SPXRECOHANDLE hreco)
{
    SPX_INIT_HR(hr);
    
    try
    {
        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];
        precognizer->Disable();
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_IsEnabled(SPXRECOHANDLE hreco, bool* pfEnabled)
{
    SPX_INIT_HR(hr);

    try
    {
        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];
        *pfEnabled = precognizer->IsEnabled();
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_SetParameter_String(SPXRECOHANDLE hreco, const wchar_t* name, const wchar_t* value)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_GetParameter_String(SPXRECOHANDLE hreco, const wchar_t* name, wchar_t* value, uint32_t cchValue)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_SetParameter_Int32(SPXRECOHANDLE hreco, const wchar_t* name, int32_t value)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_GetParameter_Int32(SPXRECOHANDLE hreco, const wchar_t* name, int32_t* pvalue)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_Recognize(SPXRECOHANDLE hreco, SPXRESULTHANDLE* phresult)
{
    SPX_INIT_HR(hr);
    *phresult = SPXHANDLE_INVALID;

    SPXASYNCHANDLE hasync = SPXHANDLE_INVALID;
    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_RecognizeAsync(hreco, &hasync));
    }

    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_RecognizeAsync_WaitFor(hasync, UINT32_MAX, phresult));
    }

    if (hasync != SPXHANDLE_INVALID)
    {
        // Don't overwrite error code from earlier function calls when cleaning up async handles
        SPX_REPORT_ON_FAIL(/* hr = */ Recognizer_AsyncHandle_Close(hasync));
        hasync = SPXHANDLE_INVALID;
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_RecognizeAsync(SPXRECOHANDLE hreco, SPXASYNCHANDLE* phasync)
{
    SPX_INIT_HR(hr);

    try
    {
        *phasync = SPXHANDLE_INVALID;

        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];

        auto asyncop = precognizer->RecognizeAsync();
        auto ptr = std::make_shared<CSpxAsyncOp<std::shared_ptr<ISpxRecognitionResult>>>(std::move(asyncop));

        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<std::shared_ptr<ISpxRecognitionResult>>, SPXASYNCHANDLE>();
        *phasync = asynchandles->TrackHandle(ptr);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_RecognizeAsync_WaitFor(SPXASYNCHANDLE hasync, uint32_t milliseconds, SPXRESULTHANDLE* phresult)
{
    SPX_INIT_HR(hr);

    try
    {
        *phresult = SPXHANDLE_INVALID;

        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<std::shared_ptr<ISpxRecognitionResult>>, SPXASYNCHANDLE>();
        auto asyncop = (*asynchandles)[hasync];

        hr = SPXERR_TIMEOUT;
        auto completed = asyncop->WaitFor(milliseconds);

        if (completed)
        {
            auto result = asyncop->Future.get();
            auto resulthandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognitionResult, SPXRESULTHANDLE>();
            *phresult = resulthandles->TrackHandle(result);
            hr = SPX_NOERROR;
        }
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StartContinuousRecognition(SPXRECOHANDLE hreco)
{
    SPX_INIT_HR(hr);   

    SPXASYNCHANDLE hasync = SPXHANDLE_INVALID;
    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_StartContinuousRecognitionAsync(hreco, &hasync));
    }

    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_StartContinuousRecognitionAsync_WaitFor(hasync, UINT32_MAX));
    }

    if (hasync != SPXHANDLE_INVALID)
    {
        // Don't overwrite error code from earlier function calls when cleaning up async handles
        SPX_REPORT_ON_FAIL(/* hr = */ Recognizer_AsyncHandle_Close(hasync));
        hasync = SPXHANDLE_INVALID;
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StartContinuousRecognitionAsync(SPXRECOHANDLE hreco, SPXASYNCHANDLE* phasync)
{
    SPX_INIT_HR(hr);
    
    try
    {
        *phasync = SPXHANDLE_INVALID;

        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];

        auto asyncop = precognizer->StartContinuousRecognitionAsync();
        auto ptr = std::make_shared<CSpxAsyncOp<void>>(std::move(asyncop));

        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        *phasync = asynchandles->TrackHandle(ptr);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StartContinuousRecognitionAsync_WaitFor(SPXASYNCHANDLE hasync, uint32_t milliseconds)
{
    // TODO: ROBCH: Consider: Move this to CSpxAsyncOp::WaitFor<void>(hasync, milliseconds); call from all _WaitFor void C apis
    SPX_INIT_HR(hr);

    try
    {
        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        auto asyncop = (*asynchandles)[hasync];

        auto completed = asyncop->WaitFor(milliseconds);
        hr = completed ? SPX_NOERROR : SPXERR_TIMEOUT;
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StopContinuousRecognition(SPXRECOHANDLE hreco)
{
    SPX_INIT_HR(hr);

    SPXASYNCHANDLE hasync = SPXHANDLE_INVALID;
    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_StopContinuousRecognitionAsync(hreco, &hasync));
    }

    if (SPX_SUCCEEDED(hr))
    {
        SPX_REPORT_ON_FAIL(hr = Recognizer_StopContinuousRecognitionAsync_WaitFor(hasync, UINT32_MAX));
    }

    if (hasync != SPXHANDLE_INVALID)
    {
        // Don't overwrite error code from earlier function calls when cleaning up async handles
        SPX_REPORT_ON_FAIL(/* hr = */ Recognizer_AsyncHandle_Close(hasync));
        hasync = SPXHANDLE_INVALID;
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StopContinuousRecognitionAsync(SPXRECOHANDLE hreco, SPXASYNCHANDLE* phasync)
{
    SPX_INIT_HR(hr);

    try
    {
        *phasync = SPXHANDLE_INVALID;

        auto recohandles = CSpxSharedPtrHandleTableManager::Get<ISpxRecognizer, SPXRECOHANDLE>();
        auto precognizer = (*recohandles)[hreco];

        auto asyncop = precognizer->StopContinuousRecognitionAsync();
        auto ptr = std::make_shared<CSpxAsyncOp<void>>(std::move(asyncop));

        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        *phasync = asynchandles->TrackHandle(ptr);
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_StopContinuousRecognitionAsync_WaitFor(SPXASYNCHANDLE hasync, uint32_t milliseconds)
{
    // TODO: ROBCH: Consider: Move this to CSpxAsyncOp::WaitFor<void>(hasync, milliseconds); call from all _WaitFor void C apis
    SPX_INIT_HR(hr);

    try
    {
        auto asynchandles = CSpxSharedPtrHandleTableManager::Get<CSpxAsyncOp<void>, SPXASYNCHANDLE>();
        auto asyncop = (*asynchandles)[hasync];

        auto completed = asyncop->WaitFor(milliseconds);
        hr = completed ? SPX_NOERROR : SPXERR_TIMEOUT;
    }
    catch (SPXHR hr)
    {
        SPX_RETURN_HR(hr);
    }
    catch (std::exception ex)
    {
        SPX_RETURN_HR(SPXERR_UNHANDLED_EXCEPTION);
    }

    SPX_RETURN_HR(hr);
}

SPXAPI Recognizer_SessionStarted_SetEventCallback(SPXRECOHANDLE hreco, PSESSION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_SessionStopped_SetEventCallback(SPXRECOHANDLE hreco, PSESSION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_SoundStarted_SetEventCallback(SPXRECOHANDLE hreco, PSESSION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_SoundStopped_SetEventCallback(SPXRECOHANDLE hreco, PSESSION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_IntermediateResult_SetEventCallback(SPXRECOHANDLE hreco, PRECOGNITION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_FinalResult_SetEventCallback(SPXRECOHANDLE hreco, PRECOGNITION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_NoMatch_SetEventCallback(SPXRECOHANDLE hreco, PRECOGNITION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_Canceled_SetEventCallback(SPXRECOHANDLE hreco, PRECOGNITION_CALLBACK_FUNC* pCallback, void* pvContext)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_SessionEvent_GetSessionId(SPXEVENTHANDLE hevent, wchar_t* pszSessionId, uint32_t cchSessionId)
{
    return SPXERR_NOT_IMPL;
}

SPXAPI Recognizer_RecognitionEvent_GetResult(SPXEVENTHANDLE hevent, SPXRESULTHANDLE* phresult)
{
    return SPXERR_NOT_IMPL;
}
