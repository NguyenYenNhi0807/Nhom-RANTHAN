# HỆ THỐNG QUẢN LÝ ĐƠN HÀNG VẬN CHUYỂN

## 1. Giới thiệu đề tài

Ứng dụng Console được xây dựng bằng ngôn ngữ C++, vận dụng lập trình hướng đối tượng (OOP) để mô phỏng quy trình tạo và quản lý đơn hàng vận chuyển trong nước và quốc tế.

Chương trình hỗ trợ tạo đơn hàng, quản lý thông tin hàng hóa, khách hàng, gói vận chuyển, voucher và tính toán tổng chi phí thanh toán.

## 2. Chức năng chính

- Tạo đơn hàng vận chuyển trong nước.
- Tạo đơn hàng vận chuyển quốc tế.
- Nhập và quản lý thông tin hàng hóa.
- Quản lý thông tin khách hàng.
- Lựa chọn gói vận chuyển: cơ bản, nhanh, hỏa tốc.
- Áp dụng voucher và tính toán chi phí.
- Tính tổng tiền đơn hàng.
- Hiển thị thông tin chi tiết và danh sách đơn hàng.
- Giao diện Console có sử dụng màu sắc và định dạng bảng.

## 3. Kiến thức lập trình hướng đối tượng được áp dụng

Dự án vận dụng các kiến thức OOP:

- **Tính đóng gói (Encapsulation):** Sử dụng thuộc tính private/protected và các phương thức getter/setter.
- **Tính kế thừa (Inheritance):** Xây dựng các lớp dẫn xuất từ lớp cơ sở.
- **Tính đa hình (Polymorphism):** Ghi đè các phương thức ảo để xử lý nghiệp vụ riêng của từng loại đối tượng.
- **Nạp chồng toán tử (Operator Overloading):** Sử dụng toán tử nhập/xuất `>>` và `<<`.
- **Quản lý bộ nhớ động:** Sử dụng con trỏ và danh sách đối tượng.

## 4. Thiết kế các lớp chính

### 4.1. Nhóm lớp đơn hàng

- `DonHang`: Lớp cơ sở quản lý thông tin chung của đơn hàng.
- `DonHangTrongNuoc`: Lớp dẫn xuất xử lý đơn hàng trong nước.
- `DonHangQuocTe`: Lớp dẫn xuất xử lý đơn hàng quốc tế và phí hải quan.

Các phương thức đa hình tiêu biểu:
- `TinhTongTien()`
- `InThongTin()`
- `nhapDonHang()`
- `xuatDonHang()`

### 4.2. Nhóm lớp hàng hóa

- `HangHoa`: Lớp cơ sở quản lý thông tin hàng hóa.
- `HangHoaThuong`: Hàng hóa thông thường.
- `HangHoaDacBiet`: Hàng hóa đặc biệt.
- `HangHoaCongKenh`: Hàng hóa cồng kềnh.

### 4.3. Nhóm lớp khách hàng

- `KhachHang`: Lớp cơ sở quản lý thông tin khách hàng.
- `KhachHangDong`
- `KhachHangBac`
- `KhachHangVang`
- `KhachHangKimCuong`

Các lớp dẫn xuất xử lý thông tin phân hạng và ưu đãi tương ứng.

### 4.4. Các lớp hỗ trợ

| Lớp | Chức năng |
|---|---|
| `Code` | Quản lý mã đơn hàng |
| `Date` | Xử lý ngày tháng |
| `ThongTinVanChuyen` | Quản lý phương thức vận chuyển và phí vận chuyển |
| `Voucher` | Quản lý voucher |
| `ThanhToan` | Tổng hợp chi phí và thanh toán |
| `GiaoDien` | Xây dựng giao diện Console |

## 5. Cấu trúc mã nguồn

Các tệp mã nguồn được tổ chức thành hai nhóm:

- **Tệp `.h`:** Khai báo lớp, thuộc tính và phương thức.
- **Tệp `.cpp`:** Định nghĩa phương thức và xử lý nghiệp vụ.

Các tệp chính:

- `main.cpp`
- `Code.h`, `Code.cpp`
- `Date.h`, `Date.cpp`
- `DonHang.h`, `DonHang.cpp`
- `DonHangTrongNuoc.h`, `DonHangTrongNuoc.cpp`
- `DonHangQuocTe.h`, `DonHangQuocTe.cpp`
- `HangHoa.h`, `HangHoa.cpp`
- `KhachHang.h`, `KhachHang.cpp`
- `ThanhToan.h`, `ThanhToan.cpp`
- `ThongTinVanChuyen.h`, `ThongTinVanChuyen.cpp`
- `Voucher.h`, `Voucher.cpp`
- `GiaoDien.h`, `GiaoDien.cpp`

## 6. Yêu cầu môi trường

- Hệ điều hành: Windows.
- Trình biên dịch: GCC/G++.
- Chuẩn ngôn ngữ: C++11.
- Có thể sử dụng MinGW-w64 hoặc Visual Studio Code.

Kiểm tra trình biên dịch:

```bash
g++ --version
```

## 7. Hướng dẫn biên dịch và chạy chương trình

### Bước 1: Mở Terminal

Di chuyển đến thư mục chứa mã nguồn dự án.

### Bước 2: Biên dịch

Sử dụng lệnh:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic Code.cpp Date.cpp DonHang.cpp DonHangQuocTe.cpp DonHangTrongNuoc.cpp HangHoa.cpp KhachHang.cpp ThanhToan.cpp ThongTinVanChuyen.cpp Voucher.cpp GiaoDien.cpp main.cpp -o detai7_app.exe
```

### Bước 3: Chạy chương trình

Trên PowerShell:

```powershell
.\detai7_app.exe
```

Trên Linux / GitHub Codespaces (Terminal – Bash):

```bash
./detai7_app.exe
```

## 8. Hướng dẫn sử dụng

Sau khi chạy chương trình, người dùng lựa chọn chức năng trên menu chính:

| Phím | Chức năng |
|---|---|
| `1` | Tạo đơn hàng trong nước |
| `2` | Tạo đơn hàng quốc tế |
| `3` | Xem danh sách đơn hàng |
| `0` | Thoát chương trình |

Thực hiện theo hướng dẫn trên màn hình để nhập thông tin và hoàn tất quá trình tạo đơn hàng.

## 9. Lưu ý

- Dữ liệu đơn hàng được quản lý trong bộ nhớ trong thời gian chương trình hoạt động.
- Khi thoát chương trình, dữ liệu của phiên chạy hiện tại không được giữ lại nếu chưa có chức năng lưu trữ ra tệp.
- Khi biên dịch lại sau khi chỉnh sửa mã nguồn, cần chạy lại lệnh biên dịch để cập nhật chương trình.

## 10. Thông tin đồ án

- **Học phần:** Lập trình hướng đối tượng (COMP1017).
- **Đề tài:** Vận chuyển đơn hàng.
- **Ngôn ngữ lập trình:** C++.
- **Chuẩn biên dịch:** C++11.
- **Loại ứng dụng:** Console Application.

---

**Dự án học phần Lập trình hướng đối tượng – COMP1017.**