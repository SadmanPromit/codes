# -*- mode: python ; coding: utf-8 -*-

block_cipher = None

a = Analysis(
    ['srm.py'],
    pathex=['C:\\path\\to\\your\\project'],
    binaries=[],
    datas=[
        ('C:/Users\proom/.cache/whisper/tiny.en.pt', 'whisper/models'),
        ('C:\Users/proom/.cache/huggingface\hub\models--microsoft--phi-2/', 'phi2/models'),
        ('path/to/tesseract/data', 'tesseract/data')
    ],
    hiddenimports=[
        'transformers',
        'scipy.io.wavfile',
        'gtts',
        'PIL.Image',
        'PIL.ImageGrab',
        'torch',
        'sounddevice',
        'whisper',
        'numpy',
        'pytesseract',
        'pygame'
    ],
    hookspath=[],
    runtime_hooks=[],
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
)

pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name='srm',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=True,
)

coll = COLLECT(
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name='srm'
)
