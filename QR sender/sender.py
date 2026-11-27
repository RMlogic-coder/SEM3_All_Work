import qrcode
import time
import base64
import json
import tkinter as tk
from pathlib import Path

# =========================
# CONFIG
# =========================

FILE_NAME = "lyrics.txt"
CHUNK_SIZE = 500          # characters per QR
DISPLAY_TIME = 0.5       # seconds per QR


# =========================
# READ FILE
# =========================

file_path = Path(FILE_NAME)

if not file_path.exists():
    print(f"❌ {FILE_NAME} not found!")
    exit()

text = file_path.read_text(encoding="utf-8")

chunks = [
    text[i:i + CHUNK_SIZE]
    for i in range(0, len(text), CHUNK_SIZE)
]

total_chunks = len(chunks)

print(f"📄 File: {FILE_NAME}")
print(f"📦 Chunks: {total_chunks}")
print("🚀 Starting transmission...")


# =========================
# TKINTER WINDOW
# =========================

root = tk.Tk()
root.title("QR File Transfer")
root.geometry("700x750")

qr_label = tk.Label(root)
qr_label.pack(pady=20)

status = tk.Label(
    root,
    text="Preparing...",
    font=("Arial", 18)
)
status.pack()


# =========================
# SEND QR FRAMES
# =========================

def send_frame(index):

    if index >= total_chunks:
        status.config(
            text="✅ Transfer Finished!"
        )
        return

    packet = {
        "file": FILE_NAME,
        "frame": index,
        "total": total_chunks,
        "data": chunks[index]
    }

    # Convert packet to JSON
    packet_json = json.dumps(
        packet,
        ensure_ascii=False
    )

    # Encode to compact Base64
    packet_encoded = base64.b64encode(
        packet_json.encode("utf-8")
    ).decode("ascii")

    # Generate QR
    qr = qrcode.QRCode(
        version=None,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4
    )

    qr.add_data(packet_encoded)
    qr.make(fit=True)

    img = qr.make_image()

    # Convert to Tkinter-compatible image
    from PIL import ImageTk

    tk_img = ImageTk.PhotoImage(img)

    qr_label.config(image=tk_img)
    qr_label.image = tk_img

    status.config(
        text=f"📡 Frame {index + 1} / {total_chunks}"
    )

    # Next frame
    root.after(
        int(DISPLAY_TIME * 1000),
        lambda: send_frame(index + 1)
    )


# =========================
# START
# =========================

send_frame(0)

root.mainloop()