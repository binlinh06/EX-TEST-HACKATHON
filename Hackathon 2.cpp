#include<stdio.h>
int main(){
	int rows,cols,choice,x;
	int arr[50][50];
	int tich=1;
	int found=0;
	do{
		printf("\n-------------MENU-------------\n");
		printf("1. Nhap kich co va gan gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch(choice){
        	
        	case 1:
        		printf("Nhap so hang: ");
        		scanf("%d",&rows);
        		printf("Nhap so cot: ");
        		scanf("%d",&cols);
        		if (rows <= 0 || cols <=0) {
                    printf("Kich co ma tran khong hop le, vui long nhap lai.\n");
                    break;
                }
        		for(int i=0;i<rows;i++){
        			for(int j=0;j<cols;j++){
        				printf("Nhap phan tu [%d][%d] la:",i,j);
        				scanf("%d",&arr[i][j]);
					}
				}
				break;
				
			case 2:
				printf("Ma tran da nhap la: ");
				for(int i=0;i<rows;i++){
					printf("\n");
					for(int j=0;j<cols;j++){
						printf("%3d",arr[i][j]);
					}
			    }
				break;
				
			case 3:
			    tich=1;
				printf("Cac phan tu duong bien la:");
				for(int i=0;i<rows;i++){
					printf("\n");
					for(int j=0;j<cols;j++){
						if(i==0||j==0||i==rows-1||j==cols-1){
							printf("%3d",arr[i][j]);
							tich*=arr[i][j];
						}
						else{
							printf("   ");
						}
					}
				}
				printf("\nTích các phan tu duong biên: %d\n", tich);
				break;
				
			case 4:
				if(rows<1||cols<1){
					printf("Chua khoi tao mang");
					continue;
				}
				if(rows!=cols){
					printf("Khong co duong cheo chinh");
				    continue;	
				}
				for(int i=0;i<rows;i++){
					printf("\n");
					for(int j=0;j<cols;j++){
						if(i==j){
							printf("%3d",arr[i][j]);	
						}else{
							printf("   ");
						}
					}
				}
			    break;
			    
			case 5:
				if(rows<1||cols<1){
					printf("Chua khoi tao mang");
					continue;
					}
				if(rows!=cols){
					printf("Khong co duong cheo phu");
					continue;
				}
				for(int i=0; i<rows; i++){
					printf("\n");
					for(int j=0;j<cols;j++){
						if(j==cols-i-1){
							printf("%d",arr[i][j]);
						}else{
							printf("   ");
						}
					}
				}
				break;
			case 6:
				if(rows<1||cols<1){
					printf("Chua khoi tao mang");
					continue;
				}
				if(rows!=cols){
					printf("Khong sap xep duoc duong cheo chinh");
					continue;
				}
				for(int i=0;i<rows-1;i++){
					for(int j=i+1;j<cols;j++){
						if(arr[i][i]>arr[j][j]){
							int temp=arr[i][i];
							arr[i][i]=arr[j][j];
							arr[j][j]=temp;
						}
					}
				}
				printf("Ma tran sau khi sap xep duong cheo chinh tang dan la:\n");
				for(int i=0;i<rows;i++){
					printf("\n");
					for(int j=0;j<cols;j++){
						printf("%3d",arr[i][j]);
					}
				}
				break;
			
			case 7:
				printf("Nhap gia tri can tim:");
				scanf("%d",&x);
				printf("Vi tri phan tu %d trong mang la: ",x);
				for(int i=0;i<rows;i++){
					for(int j=0;j<cols;j++){
						if(arr[i][j]==x){
							printf("arr[%d][%d]",i,j);
							found =1;
						}
					}
				}
				if(found=0){
					printf("Khong tim thay phan tu %d trong mang.\n", x);
				}else{
					printf("\n");
				}
				break;
				
			case 8:
				printf("Thoat.");
				return 0;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
		}
	}while(choice!=8);
	return 0;
}
