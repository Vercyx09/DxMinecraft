struct PSInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

PSInput VSMain(uint vertexID : SV_VertexID)
{
    float4 positions[3] =
    {
        float4(0.0f, 0.5f, 0.0f, 1.0f),
        float4(0.5f, -0.5f, 0.0f, 1.0f),
        float4(-0.5f, -0.5f, 0.0f, 1.0f)
    };

    float4 colors[3] =
    {
        float4(1, 0, 0, 1),
        float4(0, 1, 0, 1),
        float4(0, 0, 1, 1)
    };

    PSInput output;
    output.position = positions[vertexID];
    output.color = colors[vertexID];
    return output;
}

float4 PSMain(PSInput input) : SV_TARGET
{
    return input.color;
}
