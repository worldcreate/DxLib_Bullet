xof 0303txt 0032
template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}


Mesh {
 20;
 28.730158;-5.753960;216.301254;,
 1069.82935;-5.753960;-105.004288;,
 1009.15735;-5.753960;324.287323;,
 805.88068;-5.753960;688.82025;,
 521.38446;-5.753960;925.77502;,
 202.991989;-5.753960;1036.14050;,
 -145.532089;-5.753960;1036.14050;,
 -529.14551;-5.753960;966.46625;,
 -920.26996;-5.753960;736.30786;,
 -1168.33093;-5.753960;280.690643;,
 246.895370;-5.753960;-273.706177;,
 951.57434;-5.753960;-426.227020;,
 -1131.90027;-5.753960;-65.924347;,
 28.730158;-5.753960;-229.204575;,
 -374.666718;-5.753960;-146.918976;,
 -153.107651;-5.753960;-192.113022;,
 -125.772720;8.697639;-134.500565;,
 -109.404152;8.697639;-107.789421;,
 -99.061516;8.697639;-150.869049;,
 -82.692924;8.697639;-124.157913;;
 17;
 3;0,1,11;,
 3;0,2,1;,
 3;0,3,2;,
 3;0,4,3;,
 3;0,5,4;,
 3;0,6,5;,
 3;0,7,6;,
 3;0,8,7;,
 3;0,9,8;,
 3;0,12,9;,
 3;13,0,10;,
 3;14,0,15;,
 3;15,0,13;,
 3;11,10,0;,
 3;12,0,14;,
 3;16,17,19;,
 3;16,19,18;;

 MeshNormals {
  20;
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;;
  17;
  3;0,1,11;,
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,12,9;,
  3;13,0,10;,
  3;14,0,15;,
  3;15,0,13;,
  3;11,10,0;,
  3;12,0,14;,
  3;16,17,19;,
  3;16,19,18;;
 }

 MeshTextureCoords {
  20;
  2.001271;-10.813249;,
  56.455269;5.985128;,
  53.279236;-16.467445;,
  42.645050;-35.532074;,
  27.763716;-47.923553;,
  11.110332;-53.693886;,
  -7.118299;-53.691658;,
  -27.181742;-50.045074;,
  -47.637001;-38.004749;,
  -60.608261;-14.173307;,
  13.414961;14.813899;,
  50.272308;22.786589;,
  -58.700634;3.955240;,
  2.004121;12.487756;,
  -19.095011;8.186605;,
  -7.506661;10.548942;,
  3.125400;-3.902816;,
  5.361804;0.891627;,
  -1.669039;-1.666393;,
  0.567365;3.128051;;
 }

 MeshMaterialList {
  2;
  17;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1;

  Material {
   0.500000;0.500000;0.600000;1.000000;;
   10.000000;
   0.020000;0.020000;0.020000;;
   0.300000;0.300000;0.300000;;

   TextureFilename {
    "ntex/N_ocean.png";
   }
  }

  Material {
   0.941176;0.992157;1.000000;0.330000;;
   101.000000;
   0.000000;0.000000;0.000000;;
   0.411765;0.454902;0.478431;;

   TextureFilename {
    "ntex/N_water.png";
   }
  }
 }
}