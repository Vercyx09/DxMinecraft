cbuffer cbPerPass : register(b0)
{
    float4x4 gWorldViewProj;
};

cbuffer cbPerChunk : register(b1)
{
    float4x4 chunkWorld;
}

Texture2DArray gTextureAtlas : register(t0);
SamplerState gSamPointClamp : register(s1);

struct VertexIn
{
    float3 PosL : POSITION; // local position
    float3 Normal : NORMAL; // vertex normal
    uint TexIndex : TEXINDEX0; // main texture index
    uint OverlayTexIndex : TEXINDEX1; // overlay texture index
    float2 TexC : TEXCOORD; // texture UV
    float4 TintColor : COLOR0; // textureTint (R8G8B8A8_UNORM -> float4 0-1)
    float4 OverlayTintColor : COLOR1; // overlayTint (R8G8B8A8_UNORM -> float4 0-1)
};

struct VertexOut
{
    float4 PosH : SV_POSITION; // homogeneous clip-space position
    uint TexIndex : TEXINDEX0; // main texture index
    uint OverlayTexIndex : TEXINDEX1; // overlay texture index
    float2 TexC : TEXCOORD; // texture UV
    float4 TintColor : COLOR0; // textureTint (R8G8B8A8_UNORM -> float4 0-1)
    float4 OverlayTintColor : COLOR1; // overlayTint (R8G8B8A8_UNORM -> float4 0-1)
};

VertexOut VS(VertexIn vin)
{
    VertexOut vout;
    
    float4 worldPos = mul(float4(vin.PosL, 1.0f), chunkWorld);
    
    vout.PosH = mul(worldPos, gWorldViewProj);
    vout.TexIndex = vin.TexIndex;
    vout.OverlayTexIndex = vin.OverlayTexIndex;
    vout.TexC = vin.TexC;
    vout.TintColor = vin.TintColor;
    vout.OverlayTintColor = vin.OverlayTintColor;
    
    return vout;
}

float4 PS(VertexOut pin) : SV_Target
{
    float4 baseColor = gTextureAtlas.Sample(gSamPointClamp, float3(pin.TexC, pin.TexIndex)) * pin.TintColor;
    
    float4 overlay = gTextureAtlas.Sample(gSamPointClamp, float3(pin.TexC, pin.OverlayTexIndex));// * pin.OverlayTintColor;
    //float mask = step(0.25, overlay.a);
    
    if (overlay.a > 0.2f)
    {
        return float4(overlay.rgb * pin.OverlayTintColor.rgb, 1.0f);
    }
    else
    {
        return baseColor;
    }
    
    //float4 finalColor = lerp(baseColor, overlay, mask);
    
   // float4 finalColor = baseColor + overlay;
    
   // return finalColor;
}