<?php
echo "-------------------------------------------\r\n";

while(1){
$s=rand();
$s="0e".$s;
if(md5($s)==$s) {
echo $s;
echo "\r\n";
echo md5($s)."\r\n";
}
}
