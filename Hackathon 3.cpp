# include<stdio.h>
int main(){
	int choice;
	int i,n,arr[100];
	int index,sum,cout,max,max_2,min,min_2,val,pos,key,j,x,start,end,mid,temp;
	int check,m,b[100];
	do{
		printf("\n-------------MENU-------------\n");
		printf("1.Nhap so luong va gia tri cho cac phan tu\n");
		printf("2.In mang(ar[0]=...,arr[1]=...)\n");
		printf("3.Dem so luong so hoan hao\n");
		printf("4.Dem so luong so nguyen to\n");
		printf("5.Tim gia tri lon thu 2 (khong sap xep)\n");
		printf("6.Tim gia tri nho thu 2 (khong sap xep)\n");
		printf("7.Them phan tu tai vi tri\n");
		printf("8.Xoa phan tu tai vi tri\n");
		printf("9.Sap xep mang tang dan (sap xep chen)\n");
		printf("10.Sap xep mang giam dan (sap xep chen)\n");
		printf("11.Tim kiem phan tu(Tim kiem nhi phan)\n");
		printf("12.Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13.Sap xep va hien thi so chan dung truoc, so le dung sau\n");
		printf("14.Sap xep va hien thi so le dung truoc, so chan dung sau\n");
		printf("15. Dao nguoc mang\n");
		printf("16.Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:
				printf("Nhap so luong: ");
				scanf("%d",&n);
				printf("Nhap gia tri: \n");
				for(i=0;i<n;i++){
					scanf("%d",&arr[i]);
				}
				printf(" \n");
				break;
			
			case 2:
				printf("mang la:\n");
				for(i=0;i<n;i++){
					printf("arr[%d]= %d\n",i,arr[i]);
				}
				printf(" \n");
				break;
			
			case 3:
			    index = 0;
		        for(i=0;i<n;i++){
	                sum=0;
		    	    int a;
					for(a=1;a<arr[i];a++){
		    	     	if(arr[i]%a==0){
		    			    sum=sum+a;
					    }
				    }
				    if(sum==arr[i]){
						index++;
				    }
			    }
				printf("Co %d so la so hoan hao",index);
				printf(" \n");
		    	break;
			
			case 4:
				cout=0;
				for(i=0;i<n;i++){
					if(arr[i]<10){
						switch(arr[i]){
							case 2:
						    case 3:
						    case 5:
						    case 7:
						    	cout+=1;
						}
					}else if(arr[i]%2!=0&&arr[i]%3!=0&&arr[i]%5!=0&&arr[i]%7!=0){
					    cout+=1;
					}
				}
				printf("so luong so nguyen la: %d",cout);
				printf(" \n");
				break;
			
			case 5:
		     	max = arr[0];
		    	for(i=0;i<n;i++){
		    		if(arr[i]>max){
		    			max_2=max;
		    			max=arr[i];
					}else if(arr[i]>max_2){
						max_2=arr[i];
					}
				}
				printf("So lon thu 2 trong mang la: %d",max_2);
				printf(" \n");
		    	break;
		    	
			case 6:
		     	min = arr[0];
		        for(i=0;i<n;i++){
		    		if(arr[i]<min){
		    			min_2=min;
		    			min=arr[i];
					}else if(arr[i]<min_2){
						min_2=arr[i];
					}
				}
				printf("So nho thu 2 trong mang la: %d",min_2);
				printf(" \n");
		    	break;

			case 7:
				printf("nhap gia tri muon them: ");
				scanf("%d",&val);
				printf("nhap vi tri muon them: ");
				scanf("%d",&pos);
				if(pos<0||pos>n){
					printf("vi tri khong hop le");
				}else{
					for(i=n;i>=pos;i--){
						arr[i]=arr[i-1];
					}
					arr[pos]=val;
					n++;
				}
		        printf(" \n");
				break;

			case 8:
				printf("nhap vi tri muon xoa: ");
				scanf("%d",&pos);
				if(pos<0||pos>n){
					printf("vi tri khong hop le");
				}else{
					for(i=pos;i<n-1;i++){
						arr[i]=arr[i+1];
					}
					n--;
				}
		        printf(" \n");
				break;

			case 9:
				for(i=1;i<n;i++){
					key=arr[i];
					j=i-1;
					for(j=i-1;j>=0&&arr[j]>=key;j--){
						arr[j+1]=arr[j];
					}
					arr[j+1]=key;
				}
                printf(" \n");
				break;

			case 10:
				for(i=1;i<n;i++){
					key=arr[i];
					j=i-1;
					for(j=i-1;j>=0&&arr[j]<key;j--){
						arr[j+1]=arr[j];
					}
					arr[j+1]=key;
				}
                printf(" \n");
				break;

			case 11:
	        	start=0;
	        	end=n;
                printf("nhap mot so: ");
	            scanf("%d",&x);
				while(start<=end){
		            mid=(start+end)/2;
	              	if(arr[mid]==x){
			            break;
		            }else if(arr[mid]>x){
			            end=mid-1;
		            }else{
			            start=mid+1;
		            }
	            }
	            if(arr[mid]==x){
		            printf("vi tri cua phan tu giong %d la: %d",x,mid);
	            }else{
		            printf("khong co phan tu nay trong mang\n");
	            }
	            printf(" \n");
				break;
			
			case 12:
				check=0;
				for(i=0;i<n;i++){
					check=0;
					for(j=0;j<m;j++){
						if(arr[i]==b[j]){
							check=1;
							break;
					    }
					}
					if(!check){
						b[m++]=arr[i];	
					}
				}
				for(i=0;i<m;i++){
                    arr[i]=b[i];
                }
				n=m;
				printf("Mang sau khi xoa phan tu trung lap: ");
                for (i=0;i<n;i++){
                    printf("%d ",arr[i]);
                }
                printf(" \n");
				break;

			case 13:
				for(i=0;i<n;i++){
                    for(j=0;j<n-i-1;j++){
                        if((arr[j]%2>arr[j+1]%2) || (arr[j]%2==arr[j+1]%2 && arr[j]>arr[j+1])){ 
                            temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep so chan truoc, so le sau: ");
                for(i=0;i<n;i++){
                    printf("%d ", arr[i]);
                }
                printf(" \n");
				break;

			case 14:
				for(i=0;i<n;i++){
                    for(j=0;j<n-i-1;j++){
                        if((arr[j]%2<arr[j+1]%2) || (arr[j]%2==arr[j+1]%2 && arr[j]>arr[j+1])){ 
                            temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep so le truoc, so chan sau: ");
                for(i=0;i<n;i++){
                    printf("%d ", arr[i]);
                }
                printf(" \n");
				break;

			case 15:
				printf("mang sau khi dao nguoc la:\n");
				for(i=n;i>=0;i--){
					printf("arr[%d]= %d\n",i,arr[i]);
				}
				printf(" \n");
				break;

			case 16:
				printf(" \n");
				break;
			default:
				printf("lua chon khong hop le");
	    }	    
	}while(choice!=16);
    return 0;
}
