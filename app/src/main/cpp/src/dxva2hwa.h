#ifndef __FANPLAYER_DXVA2HWA_H__
#define __FANPLAYER_DXVA2HWA_H__

#ifdef __cplusplus
extern "C" {
#endif

// ����ͷ�ļ�
#include "libavcodec/avcodec.h"

// ��������
int  dxva2hwa_init(AVCodecContext *ctxt, void *d3ddev, void *hwnd);
void dxva2hwa_free(AVCodecContext *ctxt);
void dxva2hwa_lock_frame  (AVFrame *dxva2frame, AVFrame *lockedframe);
void dxva2hwa_unlock_frame(AVFrame *dxva2frame);

#ifdef __cplusplus
}
#endif

#endif


