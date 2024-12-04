#include <stdio.h>
int main() {
    int MAX;    
    int arr[100];
    int n = 0;
    int luaChon,value,position,size,i,x;
    int found=0;
    do {
        printf("\n---------------MENU---------------\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat trong mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon){

            case 1: 
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;


            case 2: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao!\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            
            case 3: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao!\n");
                } else {
                    int lonNhat = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > lonNhat){
                        	lonNhat = arr[i];
						}
                    }
                    printf("Gia tri lon nhat: %d\n", lonNhat);
                }
                break;
            
            case 4:{
            	if(n <= 0){
					printf("Mang chua duoc tao \n");
					break;
				}else{
					printf("Cac phan tu la so nguyen to trong mang la : ");
					for(int i = 0 ; i < n ; i++){
						int number = arr[i];
						int isPrime = 1;
						if(number < 2){
							isPrime = 0;
						}else{
							for(int i = 2 ; i*i <= number ; i++){
								if(number % i == 0){
									isPrime = 0;
									break;
								}
							}
						}
						if(isPrime){
							printf("%d \t",number);
							found = 1;
						}
					}
					if(!found){
						printf("Khong co so nguyen trong mang \n");
					}
				}
				break;
			}
                
            
            case 5: 
            	printf("Vui long nhap phan tu muon them: ");
	            scanf("%d",&value);
        	    printf("Vui long nhap vi tri muon them: ");
        	    scanf("%d",&position);
        	    if (position < 1 || position > n + 1) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
        	    for(int i=n;i>=position;i--){
      	            arr[i]=arr[i-1];
        	    }
        	    arr[position-1]=value;
        	    n++;    
         	    break;
            
            case 6: 
                printf("Vui long nhap vi tri muon xoa: ");
	            scanf("%d",&position);
	            if (position < 1 || position > n + 1) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
	            for(int i=position-1;i<n;i++){
		            arr[i]=arr[i+1];
	            }
	            n--;
	            break;
            
            case 7: 
                for(int i=1;i<5;i++){
    	            int key=arr[i];
    	            int j;
    	            for(j=i-1;j>=0&&arr[j]>key;j--){
    	                arr[j+1]=arr[j];
			        }
			    arr[j+1]=key;
		        }
                break;
            
            case 8:
            	printf("Vui long nhap 1 so bat ki de tim vi tri:");
                scanf("%d",&x);
                for(int i=0;i<n;i++){
                	if(arr[i]==x){
                		printf("Vi tri phan tu can tim o vi tri %d\n",i+1);
                		found=1;
					}
				}
				if(found==0){
					printf("Khong tim thay phan tu %d trong mang.\n", x);
				}else{
					printf("\n");
				}
	            break;
            case 9: {
                printf("Thoat chuong trinh.\n");
                break;
                }
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
    }
    } while (luaChon != 9);
    return 0;
}
