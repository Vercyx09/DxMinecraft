cbuffer cbPerPass : register(b0)
{
    float4x4 gWorldViewProj;
};

cbuffer cbPlayer : register(b1)
{
    float4x4 playerWorld;
}

struct VertexIn
{
    float3 PosL : POSITION; // local position
};

struct VertexOut
{
    float4 PosH : SV_POSITION; // homogeneous clip-space position
    float4 Color : COLOR; // Color
};

VertexOut VS(VertexIn vin)
{
    VertexOut vout;
    
    float4 worldPos = mul(float4(vin.PosL, 1.0f), playerWorld);
    
    vout.PosH = mul(worldPos, gWorldViewProj);
    vout.Color = float4(1.0f, 0.0f, 0.0f, 1.0f);    
    
    return vout;
}

float4 PS(VertexOut pin) : SV_Target
{
    return pin.Color;
}