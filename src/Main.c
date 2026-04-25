//#define IMAGE_PNG_ONLY

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/DD7Segment.h"


#define CLOCK_MAX		60
#define CLOCK_H_MAX		12

Vec2 Clock_Rad;
float Clock_Time_H;
float Clock_Time_M;
float Clock_Time_S;

void Clock_RenderPointer(Vec2 p,Vec2 t,Pixel c){
	//Line_RenderX(WINDOW_STD_ARGS,p,t,c,1.0f);

	const Vec2 n = Vec2_Norm(Vec2_Sub(t,p));
	const Vec2 np = Vec2_Perp(n);
	const Vec2 na = Vec2_PerpA(n);
	
	Triangle_RenderX(
		WINDOW_STD_ARGS,
		Vec2_Add(p,Vec2_Mul(np,Clock_Rad)),
		Vec2_Add(p,Vec2_Mul(na,Clock_Rad)),
		t,
		c
	);
}

void Setup(AlxWindow* w){
	Clock_Rad = (Vec2){ 0.0f,0.0f };
	Clock_Time_H = 0.0f;
	Clock_Time_M = 0.0f;
	Clock_Time_S = 0.0f;
}
void Update(AlxWindow* w){
	char buffer[128];
	memset(buffer,0,sizeof(buffer));
	Time_Str(buffer,Time_Real_Nano());
	printf("\r%s",buffer);

	TimeStamp now = Time_Get(Time_Real_Nano());

	Clock_Rad = (Vec2){ (float)GetWidth() * 0.025f,(float)GetHeight() * 0.025f };
	Clock_Time_S = (float)now.Sec / (float)CLOCK_MAX;
	Clock_Time_M = (float)now.Min / (float)CLOCK_MAX + (Clock_Time_S / (float)CLOCK_MAX);
	Clock_Time_H = (float)now.Hour / (float)CLOCK_H_MAX + (Clock_Time_M / (float)CLOCK_MAX);
	
	Clear(BLACK);

	const Vec2 a_h = Vec2_OfAngle(F32_PI2 * Clock_Time_H - F32_PI05);
	const Vec2 a_m = Vec2_OfAngle(F32_PI2 * Clock_Time_M - F32_PI05);
	const Vec2 a_s = Vec2_OfAngle(F32_PI2 * Clock_Time_S - F32_PI05);

	const Vec2 p = { GetWidth() / 2,GetHeight() / 2 };
	const Vec2 l = { GetWidth() / 2,GetHeight() / 2 };
	Circle_R_Render(WINDOW_STD_ARGS,p,l,WHITE);
	Circle_R_RenderWire(WINDOW_STD_ARGS,p,l,GRAY,1.0f);

	for(int i = 0;i<CLOCK_MAX;i++){
		const float a = (float)i / (float)CLOCK_MAX * F32_PI2;
		const float len = i % 5 == 0 ? 0.90f : 0.95f;
		const Vec2 va = Vec2_OfAngle(a);
		const Vec2 vas = Vec2_Mul(l,va);
		const Vec2 vasl = Vec2_Mulf(vas,len);

		const Vec2 s = Vec2_Add(p,vas);
		const Vec2 t = Vec2_Add(p,vasl);
		Line_RenderX(WINDOW_STD_ARGS,s,t,DARK_GRAY,1.0f);
	}

	Clock_RenderPointer(p,Vec2_Add(p,Vec2_Mulf(Vec2_Mul(l,a_h),0.50f)),RED);
	Clock_RenderPointer(p,Vec2_Add(p,Vec2_Mulf(Vec2_Mul(l,a_m),0.75f)),BLUE);
	Clock_RenderPointer(p,Vec2_Add(p,Vec2_Mulf(Vec2_Mul(l,a_s),1.00f)),BLACK);

	Circle_R_Render(WINDOW_STD_ARGS,p,Clock_Rad,GRAY);
}
void Delete(AlxWindow* w){
	
}

int main(){
    if(Create("Analog Clock",1000,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}