--- OpenAL32/alBuffer.c.orig	2014-08-15 07:06:59 UTC
+++ OpenAL32/alBuffer.c
@@ -1179,7 +1179,7 @@ static ALboolean DecomposeFormat(ALenum 
         { AL_7POINT1_16_SOFT,  FmtX71, FmtShort },
         { AL_7POINT1_32F_SOFT, FmtX71, FmtFloat },
     };
-    ALuint i;
+    volatile ALuint i;
 
     for(i = 0;i < COUNTOF(list);i++)
     {
