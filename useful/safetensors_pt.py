# safetensors_pt: v1 © 2024 Sadman Sakib Khan Promit
import torch
from safetensors import safe_open
from transformers import AutoConfig
import os
import gc
import glob

cache_dir = "./model_cache"
os.makedirs(cache_dir, exist_ok=True)
device = "cuda" if torch.cuda.is_available() else "cpu"
model_dir = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Llama-3.1-Nemotron-70B-Instruct-HF/snapshots/fac73d3507320ec1258620423469b4b38f88df6e/"
config = AutoConfig.from_pretrained(model_dir)
safetensors_files = glob.glob(os.path.join(model_dir, "*.safetensors"))
if not safetensors_files:
    raise FileNotFoundError(f"No safetensors files found in {model_dir}")
tensor_file_map = {}
for file in safetensors_files:
    with safe_open(file, framework="pt", device="cpu") as f:
        for key in f.keys():
            tensor_file_map[key] = file

def save_tensor_group(keys, output_file):
    if not os.path.exists(output_file):
        tensors = {}
        for key in keys:
            file = tensor_file_map[key]
            with safe_open(file, framework="pt", device=device) as f:
                tensors[key.split(".", 1)[1]] = f.get_tensor(key)
        torch.save(tensors, output_file)
        del tensors
        gc.collect()
        if device == "cuda":
            torch.cuda.empty_cache()

save_tensor_group(
    [k for k in tensor_file_map if k.startswith("model.embed_tokens")],
    os.path.join(cache_dir, "embed_tokens.pt")
)
save_tensor_group(
    [k for k in tensor_file_map if k.startswith("lm_head")],
    os.path.join(cache_dir, "lm_head.pt")
)
save_tensor_group(
    [k for k in tensor_file_map if k.startswith("model.norm")],
    os.path.join(cache_dir, "norm.pt")
)
for i in range(config.num_hidden_layers):
    layer_keys = [k for k in tensor_file_map if k.startswith(f"model.layers.{i}.")]
    if layer_keys:
        output_file = os.path.join(cache_dir, f"layer_{i}.pt")
        save_tensor_group(layer_keys, output_file)
        print(f"Saved layer {i} to {output_file}")