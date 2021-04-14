#include <stdio.h>

extern "C"
{
#include <libavformat/avformat.h>
#include <libavutil/dict.h>	
}


int main()
{
	printf("hello");

	AVFormatContext* fmt_ctx = NULL;
	AVDictionaryEntry* tag = NULL;
	int ret;
	const char* filename = "test.mp4";

	//av_register_all();
	if ((ret = avformat_open_input(&fmt_ctx, filename, NULL, NULL)))
		return ret;

	while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
		printf("%s=%s\n", tag->key, tag->value);

	avformat_close_input(&fmt_ctx);

	system("PAUSE");
	
	return 0;
}