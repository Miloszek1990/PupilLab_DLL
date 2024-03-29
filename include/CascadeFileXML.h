#pragma once

#include <string>

static inline std::string BuildXmlFile()
{
	std::string xml;

	xml =  "	<\?xml version=\"1.0\"\?>\n";
	xml += "	<opencv_storage>\n";
	xml += "	<cascade>\n";
	xml += "	  <stageType>BOOST</stageType>\n";
	xml += "	  <featureType>HAAR</featureType>\n";
	xml += "	  <height>16</height>\n";
	xml += "	  <width>16</width>\n";
	xml += "	  <stageParams>\n";
	xml += "	    <boostType>GAB</boostType>\n";
	xml += "	    <minHitRate>9.9500000476837158e-01</minHitRate>\n";
	xml += "	    <maxFalseAlarm>5.0000000000000000e-01</maxFalseAlarm>\n";
	xml += "	    <weightTrimRate>9.4999999999999996e-01</weightTrimRate>\n";
	xml += "	    <maxDepth>1</maxDepth>\n";
	xml += "	    <maxWeakCount>100</maxWeakCount></stageParams>\n";
	xml += "	  <featureParams>\n";
	xml += "	    <maxCatCount>0</maxCatCount>\n";
	xml += "	    <featSize>1</featSize>\n";
	xml += "	    <mode>BASIC</mode></featureParams>\n";
	xml += "	  <stageNum>8</stageNum>\n";
	xml += "	  <stages>\n";
	xml += "	    <!-- stage 0 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>2</maxWeakCount>\n";
	xml += "	      <stageThreshold>-2.3536792397499084e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 6 6.4373679459095001e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            -9.4162827730178833e-01 9.2674618959426880e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 16 -5.5556628853082657e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            7.0626032352447510e-01 -9.4544702768325806e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 1 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>3</maxWeakCount>\n";
	xml += "	      <stageThreshold>-1.0052495002746582e+00</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 4 4.8008672893047333e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            -8.0715852975845337e-01 9.0092062950134277e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 14 -2.5212250184267759e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            7.8122025728225708e-01 -7.9421967267990112e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 19 -6.8749049678444862e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            5.9612876176834106e-01 -9.8703294992446899e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 2 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>2</maxWeakCount>\n";
	xml += "	      <stageThreshold>-2.7282893657684326e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 14 -2.5143194943666458e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            8.2852363586425781e-01 -8.1890386343002319e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 11 -1.9470805302262306e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            5.4607492685317993e-01 -9.6738284826278687e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 3 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>3</maxWeakCount>\n";
	xml += "	      <stageThreshold>-8.5485661029815674e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 7 -4.7495562583208084e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            7.5508606433868408e-01 -8.9579522609710693e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 10 6.0531087219715118e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            -8.6811012029647827e-01 5.8965092897415161e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 3 -1.1474071443080902e-01</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            9.0904879570007324e-01 -5.1470410823822021e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 4 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>2</maxWeakCount>\n";
	xml += "	      <stageThreshold>-3.7448886036872864e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 0 -4.1685245931148529e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            6.8136346340179443e-01 -9.3480545282363892e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 8 -9.0324729681015015e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            5.6031662225723267e-01 -7.8767967224121094e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 5 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>4</maxWeakCount>\n";
	xml += "	      <stageThreshold>-9.4174134731292725e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 13 -3.6699399352073669e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            6.5627264976501465e-01 -9.6412557363510132e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 1 4.6697324141860008e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            -7.8290480375289917e-01 5.7183736562728882e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 5 -1.0897557437419891e-01</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            4.5534572005271912e-01 -8.1846565008163452e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 17 -7.7747309114784002e-04</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            3.4994328022003174e-01 -9.7630101442337036e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 6 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>2</maxWeakCount>\n";
	xml += "	      <stageThreshold>-1.0677374899387360e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 18 -2.2195926867425442e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            5.9206402301788330e-01 -9.6653795242309570e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 12 -1.0557221248745918e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            8.5976421833038330e-01 -4.8659038543701172e-01</leafValues></_></weakClassifiers></_>\n";
	xml += "	    <!-- stage 7 -->\n";
	xml += "	    <_>\n";
	xml += "	      <maxWeakCount>4</maxWeakCount>\n";
	xml += "	      <stageThreshold>-3.6766102910041809e-01</stageThreshold>\n";
	xml += "	      <weakClassifiers>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 20 -3.0323667451739311e-03</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            6.7981070280075073e-01 -6.9479352235794067e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 9 -3.3002831041812897e-02</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            4.1205951571464539e-01 -9.3789011240005493e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 2 -1.6796401143074036e-01</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            7.6128369569778442e-01 -4.7675889730453491e-01</leafValues></_>\n";
	xml += "	        <_>\n";
	xml += "	          <internalNodes>\n";
	xml += "	            0 -1 15 -7.1254628710448742e-04</internalNodes>\n";
	xml += "	          <leafValues>\n";
	xml += "	            3.9183190464973450e-01 -9.5958036184310913e-01</leafValues></_></weakClassifiers></_></stages>\n";
	xml += "	  <features>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          1 1 12 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          1 3 12 2 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          1 14 8 2 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          1 14 4 1 2.</_>\n";
	xml += "	        <_>\n";
	xml += "	          5 15 4 1 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          2 1 6 13 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          5 1 3 13 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          2 5 6 5 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          5 5 3 5 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          2 5 4 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          2 7 4 2 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 1 12 8 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 1 6 4 2.</_>\n";
	xml += "	        <_>\n";
	xml += "	          9 5 6 4 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 3 3 9 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 6 3 3 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 7 3 9 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 10 3 3 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 8 3 2 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 9 3 1 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 8 4 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 11 4 3 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          3 8 12 8 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          3 8 6 4 2.</_>\n";
	xml += "	        <_>\n";
	xml += "	          9 12 6 4 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          4 2 12 2 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          8 2 4 2 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          4 7 2 2 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          5 7 1 2 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          4 10 12 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          8 10 4 6 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          5 7 3 2 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          6 7 1 2 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          7 0 4 4 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          7 0 2 2 2.</_>\n";
	xml += "	        <_>\n";
	xml += "	          9 2 2 2 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          7 2 9 11 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          10 2 3 11 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          11 10 1 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          11 12 1 2 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          12 2 3 13 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          13 2 1 13 3.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          13 0 1 8 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          13 4 1 4 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_>\n";
	xml += "	    <_>\n";
	xml += "	      <rects>\n";
	xml += "	        <_>\n";
	xml += "	          14 8 2 6 -1.</_>\n";
	xml += "	        <_>\n";
	xml += "	          14 8 1 3 2.</_>\n";
	xml += "	        <_>\n";
	xml += "	          15 11 1 3 2.</_></rects>\n";
	xml += "	      <tilted>0</tilted></_></features></cascade>\n";
	xml += "	</opencv_storage>";

	return xml;
}